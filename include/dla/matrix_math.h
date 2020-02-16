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

    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_plus_v<T, U>>>
    constexpr auto operator+(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_minus_v<T, U>>>
    constexpr auto operator-(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_multiply_v<T, U>>>
    constexpr auto operator*(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_divide_v<T, U>>>
    constexpr auto operator/(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_modulo_v<T, U>>>
    constexpr auto operator%(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_bitwise_and_v<T, U>>>
    constexpr auto operator&(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_bitwise_or_v<T, U>>>
    constexpr auto operator|(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_bitwise_xor_v<T, U>>>
    constexpr auto operator^(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_left_shift_v<T, U>>>
    constexpr auto operator<<(const mat<T, N, M>& lhs, const U& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<U> && overloads_right_shift_v<T, U>>>
    constexpr auto operator>>(const mat<T, N, M>& lhs, const U& rhs) noexcept;

    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_plus_v<T, U>>>
    constexpr auto operator+(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_minus_v<T, U>>>
    constexpr auto operator-(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_multiply_v<T, U>>>
    constexpr auto operator*(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_divide_v<T, U>>>
    constexpr auto operator/(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_modulo_v<T, U>>>
    constexpr auto operator%(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_bitwise_and_v<T, U>>>
    constexpr auto operator&(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_bitwise_or_v<T, U>>>
    constexpr auto operator|(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_bitwise_xor_v<T, U>>>
    constexpr auto operator^(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_left_shift_v<T, U>>>
    constexpr auto operator<<(const T& lhs, const mat<U, N, M>& rhs) noexcept;
    template<class T, class U, std::size_t N, std::size_t M, typename = std::enable_if_t<is_scalar_v<T> && overloads_right_shift_v<T, U>>>
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
    constexpr auto floor(const mat<T, N, M>& val) noexcept;
    template<class T, std::size_t N, std::size_t M>
    constexpr auto ceil(const mat<T, N, M>& val) noexcept;
    template<class T, std::size_t N, std::size_t M>
    constexpr auto round(const mat<T, N, M>& val) noexcept;

    template<class T, std::size_t N, std::size_t M>
    constexpr auto transpose(const mat<T, N, M>& val) noexcept;

    template<class T, class U, std::size_t N, std::size_t M, std::size_t L>
    constexpr auto dot(const mat<T, N, M>& lhs, const mat<U, M, L>& rhs);
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto dot(const mat<T, N, M>& lhs, const vec<U, M>& rhs);
    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto dot(const vec<T, N>& lhs, const mat<U, N, M>& rhs);

    template<class T, class U, std::size_t N, std::size_t M>
    constexpr auto outer_product(const vec<T, N>& lhs, const vec<U, M>& rhs);

    template<class T, std::size_t N>
    constexpr auto diagonal(const vec<T, N>& diag);
}

#include "matrix_math.inl"
