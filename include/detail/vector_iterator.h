#pragma once

#include <cstdint>

#include "detail.h"

// TODO: Conditional noexcept specifiers

namespace unit::detail {
    template<class T, std::size_t N>
    class vec_iterator {
    public:
        constexpr vec_iterator(T& vec, std::size_t startIdx) noexcept : mVec(vec), mIdx(startIdx) {}

        constexpr vec_iterator(const vec_iterator&) noexcept = default;
        constexpr vec_iterator& operator=(const vec_iterator&) noexcept = default;

        constexpr decltype(auto) operator*() const noexcept {
            return mVec[mIdx];
        }
        constexpr decltype(auto) operator*() noexcept {
            return mVec[mIdx];
        }

        constexpr decltype(auto) operator++() noexcept {
            mIdx++;
            return *this;
        }
        [[nodiscard]] constexpr auto operator++(int) noexcept {
            auto prev = *this;
            mIdx++;
            return prev;
        }

        constexpr decltype(auto) operator--() noexcept {
            mIdx--;
            return *this;
        }
        [[nodiscard]] constexpr auto operator--(int) noexcept {
            auto prev = *this;
            mIdx--;
            return prev;
        }
    
        [[nodiscard]] constexpr auto operator+(int rhs) const noexcept {
            auto res{ *this };
            res.mIdx += rhs;
            return res;
        }
        [[nodiscard]] constexpr auto operator-(int rhs) const noexcept {
            return *this + (-rhs);
        }
    
        constexpr decltype(auto) operator+=(int rhs) noexcept {
            *this = *this + rhs;
            return *this;
        }
        constexpr decltype(auto) operator-=(int rhs) noexcept {
            return *this += (-rhs);
        }

        constexpr auto operator==(const vec_iterator& rhs) noexcept {
            return &mVec == &rhs.mVec && mIdx == rhs.mIdx;
        }
        constexpr auto operator!=(const vec_iterator& rhs) noexcept {
            return &mVec != &rhs.mVec || mIdx != rhs.mIdx;
        }

    private:
        T& mVec;
        std::size_t mIdx;
    };
}
