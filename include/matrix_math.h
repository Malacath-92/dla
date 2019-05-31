#pragma once

#include <cstddef>

namespace dla {
    template<class T, std::size_t N, std::size_t M>
    struct mat;
    template<class T, std::size_t N>
    struct vec;

    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator+(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator-(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator*(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator/(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator%(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator&(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator|(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator^(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator<<(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator>>(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;

    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator+(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator-(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator*(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator/(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator%(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator&(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator|(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator^(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator<<(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U>>>
    constexpr auto operator>>(const mat<T, N, M>& lhs, const U& rhs) noexcept;

    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator+(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator-(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator*(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator/(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator%(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator&(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator|(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator^(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator<<(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T>>>
    constexpr auto operator>>(const T& lhs, const mat<U, N, M>& rhs) noexcept;

    template<class T, std::size_t N, std::size_t M>
    constexpr auto operator+(const mat<T, N, M>& val) noexcept;
    template<class T, std::size_t N, std::size_t M>
    constexpr auto operator-(const mat<T, N, M>& val) noexcept;
    template<class T, std::size_t N, std::size_t M>
    constexpr auto operator~(const mat<T, N, M>& val) noexcept;

    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator==(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto operator!=(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;

    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto compare(const mat<T, N, M>& lhs, const mat<U, N, M>& rhs) noexcept;

    template<class T, std::size_t N, std::size_t M>
    constexpr auto abs(const mat<T, N, M>& val) noexcept;

    template<class T, std::size_t N, std::size_t M>
    constexpr auto transpose(const mat<T, N, M>& val) noexcept;

    template<class T, class U, std::size_t N, std::size_t M, std::size_t L>
    constexpr auto dot(const mat<T, N, M>& lhs, const mat<U, M, L>& rhs);
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto dot(const mat<T, N, M>& lhs, const vec<U, M>& rhs);
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto dot(const vec<T, N>& lhs, const mat<U, N, M>& rhs);
}

#include "matrix_math.inl"
