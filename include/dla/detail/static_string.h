#pragma once

#include <algorithm>
#include <array>
#include <string>
#include <string_view>
#include <utility>

template<size_t Length>
class static_string
{
    template<size_t>
    friend class static_string;

  public:
    /*
            Rule of Five
    */
    constexpr static_string() = delete;
    constexpr static_string(const static_string&) noexcept = default;
    constexpr static_string(static_string&&) noexcept = default;
    constexpr static_string& operator=(const static_string&) noexcept = default;
    constexpr static_string& operator=(static_string&&) noexcept = default;
    ~static_string() = default;

    // Construct from a single string literal
    // constexpr static_string(const char(&str)[Length]) noexcept : static_string(str, std::make_index_sequence<Length>{}) {}
    constexpr static_string(const char (&str)[Length]) noexcept
    {
        for (size_t i = 0; i < Length; i++)
        {
            mData[i] = str[i];
        }
    }

    // Construct from a single char
    struct char_tag_t {};
    constexpr static_string(char c, char_tag_t) noexcept
    {
        static_assert(Length == 2);
        mData[0] = c;
        mData[1] = '\0';
    }

    /*
            Concatenation of strings
    */
    template<size_t OtherLength>
    constexpr static_string<Length + OtherLength - 1> operator+(const static_string<OtherLength>& rhs) const
    {
        constexpr size_t resultLength = Length + OtherLength - 1;
        std::array<char, resultLength> resultData = {};
        auto resultIt = resultData.begin();
        for (auto it = begin(); it != end(); ++it, ++resultIt)
            *resultIt = *it;
        resultIt--; // Note: VS will not accept iteration to 'end() - 1' because of C4308
        for (auto it = rhs.begin(); it != rhs.end(); ++it, ++resultIt)
            *resultIt = *it;
        return static_string<resultLength>(std::move(resultData));
    }
    template<size_t OtherLength>
    constexpr static_string<Length + OtherLength - 1> operator+(const char (&rhs)[OtherLength]) const
    {
        return *this + static_string<OtherLength>(rhs);
    }
    std::string operator+(const std::string& rhs) const
    {
        return c_str() + rhs;
    }

    /*
            Comparison operators
    */
    template<size_t OtherLength>
    constexpr bool operator==(const static_string<OtherLength>& rhs) const
    {
        if constexpr (OtherLength != Length)
        {
            return false;
        }
        else
        {
            return std::string_view{ mData.data() } == std::string_view{ rhs.mData.data() };
        }
    }

    /*
            Expose capacity
    */
    constexpr size_t size() const noexcept
    {
        return Length;
    }
    constexpr size_t length() const noexcept
    {
        return Length;
    }
    constexpr size_t max_size() const noexcept
    {
        return Length;
    }
    constexpr bool empty() const noexcept
    {
        return Length == 1;
    }

    /*
            Expose underlying data
    */
    constexpr char* c_str() noexcept
    {
        return mData.data();
    }
    constexpr const char* c_str() const noexcept
    {
        return mData.data();
    }

    /*
            Explicit conversion to std::string at runtime
            or std::string_view at compile time
    */
    explicit operator std::string() const
    {
        return c_str();
    }
    explicit constexpr operator std::string_view() const
    {
        return { c_str(), size() - 1 };
    }

    /*
            Expose member access of the array
    */
    constexpr char& operator[](size_t i)
    {
        return mData[i];
    }
    constexpr const char& operator[](size_t i) const
    {
        return mData[i];
    }
    constexpr char& at(size_t i)
    {
        return mData.at(i);
    }
    constexpr const char& at(size_t i) const
    {
        return mData.at(i);
    }

    /*
            Expose all iterators of the underlying array
    */
    constexpr auto begin() noexcept
    {
        return mData.begin();
    }
    constexpr auto end() noexcept
    {
        return mData.end();
    }
    constexpr auto begin() const noexcept
    {
        return mData.begin();
    }
    constexpr auto end() const noexcept
    {
        return mData.end();
    }
    constexpr auto cbegin() const noexcept
    {
        return mData.cbegin();
    }
    constexpr auto cend() const noexcept
    {
        return mData.cend();
    }

    constexpr auto rbegin() noexcept
    {
        return mData.rbegin();
    }
    constexpr auto rend() noexcept
    {
        return mData.rend();
    }
    constexpr auto rbegin() const noexcept
    {
        return mData.rbegin();
    }
    constexpr auto rend() const noexcept
    {
        return mData.rend();
    }
    constexpr auto crbegin() const noexcept
    {
        return mData.crbegin();
    }
    constexpr auto crend() const noexcept
    {
        return mData.crend();
    }

    /*
            Splicing etc.
    */
    template<std::size_t Off>
    constexpr static_string<Length - Off> substr() const
    {
        constexpr size_t resultLength = Length - Off;
        std::array<char, resultLength> resultData{};
        auto resultIt = resultData.begin();
        for (auto it = begin() + Off; it != end(); ++it, ++resultIt)
            *resultIt = *it;
        return static_string<resultLength>(std::move(resultData));
    }

  private:
    constexpr static_string(std::array<char, Length> data) noexcept
        : mData(std::move(data))
    {
    }

    std::array<char, Length> mData;
};

template<size_t LeftLength, size_t RightLength>
constexpr static_string<LeftLength + RightLength - 1> operator+(const char (&lhs)[LeftLength], const static_string<RightLength>& rhs)
{
    return static_string<LeftLength>(lhs) + rhs;
}
template<size_t RightLength>
constexpr static_string<2 + RightLength - 1> operator+(char lhs, const static_string<RightLength>& rhs)
{
    return static_string<2>{ lhs, static_string<2>::char_tag_t{} } + rhs;
}
template<size_t RightLength>
std::string operator+(const std::string& lhs, const static_string<RightLength>& rhs)
{
    return lhs + rhs.c_str();
}

template<size_t Length>
constexpr auto make_string_literal(const char (&str)[Length])
{
    return static_string<Length>(str);
}
