#pragma once

#include <cstddef>

#include "type_traits.h"
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

    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator+(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator-(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator*(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator/(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator%(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator&(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator|(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator^(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator<<(const vec<T, N>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator>>(const vec<T, N>& lhs, const U& rhs) noexcept;

    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator+(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator-(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator*(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator/(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator%(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator&(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator|(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator^(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator<<(const T& lhs, const vec<U, N>& rhs) noexcept;
    template<class T, class U, std::size_t N, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator>>(const T& lhs, const vec<U, N>& rhs) noexcept;

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
    constexpr auto abs(const vec<T, N>& val) noexcept;

    template<class T, class U, std::size_t N, class Distance = distances::euclidean<T, U>>
    DLA_OPTIMISTIC_CONSTEXPR auto distance(const vec<T, N>& lhs, const vec<U, N>& rhs, Distance&& metric = {}) noexcept;
    template<class T, std::size_t N, class Distance = distances::euclidean<T>>
    DLA_OPTIMISTIC_CONSTEXPR auto length(const vec<T, N>& val, Distance&& metric = {}) noexcept;

    template<class T, class U, std::size_t N>
    constexpr auto dot(const vec<T, N>& lhs, const vec<U, N>& rhs);
}

#include "vector_math.inl"
