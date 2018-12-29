#pragma once

#include <cmath>

namespace dla {
    template<class T, std::size_t N>
    struct vec;

    template<class T, class U, std::size_t N>
    constexpr auto operator+(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator-(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator*(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator/(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator%(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator&(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator|(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator^(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator<<(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator>>(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator+(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;

    template<class T, class U, std::size_t N>
    constexpr auto operator+(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator-(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator*(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator/(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator%(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator&(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator|(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator^(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator<<(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator>>(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator+(const vec<T, N>& lhs, const U& rhs) noexcept;

    template<class T, class U, std::size_t N>
    constexpr auto operator+(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator-(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator*(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator/(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator%(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator&(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator|(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator^(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator<<(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator>>(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator+(const T& lhs, const vec<U, N>& rhs) noexcept;

    template<class T, std::size_t N>
    constexpr auto operator+(const vec<T, N>& val) noexcept;
    template<class T, std::size_t N>
    constexpr auto operator-(const vec<T, N>& val) noexcept;
    template<class T, std::size_t N>
    constexpr auto operator~(const vec<T, N>& val) noexcept;

    template<class T, class U, std::size_t N>
    constexpr auto operator==(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N>
    constexpr auto operator!=(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;

    template<class T, class U, std::size_t N>
    constexpr auto compare(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept;
}

#include "vector_math.inl"
