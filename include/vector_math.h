#pragma once

#include "vector_distance.h"

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

    template<class T, std::size_t N>
    constexpr auto abs(const vec<T, N>& val) noexcept {
        vec<T, N> res{};
        auto val_it = val.begin();
        auto it = res.begin();
        const auto it_end = res.end();
        for (; it != it_end;) {
            *it = math::abs(*val_it);
            ++val_it;
            ++it;
        }
        return res;
    }

    template<class T, class U, std::size_t N, class Distance = distances::euclidean<T, U>>
    DLA_OPTIMISTIC_CONSTEXPR auto distance(const vec<T, N>& lhs, const vec<U, N>& rhs, Distance&& metric = {}) noexcept {
        return metric(lhs, rhs);
    }
    template<class T, std::size_t N, class Distance = distances::euclidean<T>>
    DLA_OPTIMISTIC_CONSTEXPR auto length(const vec<T, N>& val, Distance&& metric = {}) noexcept {
        constexpr vec<T, N> zero{};
        return distance(val, zero, std::move(metric));
    }

    template<class T, class U, std::size_t N>
    constexpr auto dot(const vec<T, N>& lhs, const vec<U, N>& rhs) {
        decltype(std::declval<T>() * std::declval<U>()) res{};
        auto lhs_it = lhs.begin();
        auto rhs_it = rhs.begin();
        const auto lhs_it_end = lhs.end();
        for (; lhs_it != lhs_it_end;) {
            res += *lhs_it * *rhs_it;
            ++lhs_it;
            ++rhs_it;
        }
        return res;
    }
}

#include "vector_math.inl"
