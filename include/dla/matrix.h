#pragma once

#include <stdexcept>

#include "vector.h"
#include "matrix_math.h"

#include "detail/vector_elements.h"
#include "detail/vector_iterator.h"

namespace dla {
#ifdef DLA_INDEXING_OPERATOR_THROWS_OUT_OF_BOUNDS
    inline constexpr bool mat_index_operator_is_noexcept = false;
#else
    inline constexpr bool mat_index_operator_is_noexcept = true;
#endif

    struct matrix_diagonal_t {};
    struct matrix_fill_t {};

    inline constexpr auto matrix_diagonal = matrix_diagonal_t{};
    inline constexpr auto matrix_fill = matrix_fill_t{};

    template<class T, std::size_t N, std::size_t M>
    struct mat : detail::vec_elements<vec<T, M>, N> {
        using value_type = vec<T, M>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
		using iterator = detail::vec_iterator<mat, M>;
		using const_iterator = detail::vec_iterator<const mat, M>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        using row_type = value_type;
        using col_type = vec<T, N>;

        using const_col_reference = vec<const T&, N>;
        using col_reference = vec<T&, N>;

        static constexpr std::size_t num_row = N;
        static constexpr std::size_t num_col = M;
        static constexpr std::size_t row_size = M;
        static constexpr std::size_t col_size = N;
        static constexpr std::size_t size = N;

        mat() = default;
        using vec_elements = detail::vec_elements<vec<T, M>, N>;
        using vec_elements::vec_elements;
        constexpr explicit mat(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>);
        template<bool C = (N == M), typename = std::enable_if<C>>
        constexpr explicit mat(const T& val, matrix_diagonal_t) noexcept(std::is_nothrow_copy_constructible_v<T>);
        constexpr explicit mat(const T& val, matrix_fill_t) noexcept(std::is_nothrow_copy_constructible_v<T>);

        constexpr const_reference operator[](std::size_t idx) const noexcept(mat_index_operator_is_noexcept);
        constexpr reference operator[](std::size_t idx) noexcept(mat_index_operator_is_noexcept);
        constexpr const_col_reference get_col(std::size_t idx) const noexcept(mat_index_operator_is_noexcept);
        constexpr col_reference get_col(std::size_t idx) noexcept(mat_index_operator_is_noexcept);

        template<class U>
        constexpr decltype(auto) operator+=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator-=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator*=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator/=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator%=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator&=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator|=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator^=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator<<=(const U& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator>>=(const U& rhs) noexcept;

        template<class U>
        constexpr decltype(auto) operator+=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator-=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator*=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator/=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator%=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator&=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator|=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator^=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator<<=(const mat<U, N, M>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator>>=(const mat<U, N, M>& rhs) noexcept;

        template<class U>
        constexpr auto compare(const mat<U, N, M>& rhs) const;
        template<class U, size_t L>
        constexpr auto dot(const mat<U, M, L>& rhs) const;
        template<class U>
        constexpr auto dot(const vec<U, M>& rhs) const;

        // Conversion only for size 1x1 matrices
        template<std::size_t L = N * M, typename = std::enable_if_t<L == 1>>
        constexpr operator const_reference() const noexcept;
        template<std::size_t L = N * M, typename = std::enable_if_t<L == 1>>
        constexpr operator reference() noexcept;

		constexpr iterator begin() noexcept;
		constexpr const_iterator begin() const noexcept;
		constexpr iterator end() noexcept;
		constexpr const_iterator end() const noexcept;

		constexpr reverse_iterator rbegin() noexcept;
		constexpr const_reverse_iterator rbegin() const noexcept;
		constexpr reverse_iterator rend() noexcept;
		constexpr const_reverse_iterator rend() const noexcept;

		constexpr const_iterator cbegin() noexcept;
		constexpr const_iterator cend() const noexcept;
		constexpr const_reverse_iterator crbegin() noexcept;
		constexpr const_reverse_iterator crend() noexcept;
    };

    template<class T>
    using tmat1 = mat<T, 1, 1>;
    template<class T>
    using tmat2 = mat<T, 2, 2>;
    template<class T>
    using tmat3 = mat<T, 3, 3>;
    template<class T>
    using tmat4 = mat<T, 4, 4>;

    template<class T>
    using tmat1x1 = mat<T, 1, 1>;
    template<class T>
    using tmat1x2 = mat<T, 1, 2>;
    template<class T>
    using tmat1x3 = mat<T, 1, 3>;
    template<class T>
    using tmat1x4 = mat<T, 1, 4>;

    template<class T>
    using tmat2x1 = mat<T, 2, 1>;
    template<class T>
    using tmat2x2 = mat<T, 2, 2>;
    template<class T>
    using tmat2x3 = mat<T, 2, 3>;
    template<class T>
    using tmat2x4 = mat<T, 2, 4>;

    template<class T>
    using tmat3x1 = mat<T, 3, 1>;
    template<class T>
    using tmat3x2 = mat<T, 3, 2>;
    template<class T>
    using tmat3x3 = mat<T, 3, 3>;
    template<class T>
    using tmat3x4 = mat<T, 3, 4>;

    template<class T>
    using tmat4x1 = mat<T, 4, 1>;
    template<class T>
    using tmat4x2 = mat<T, 4, 2>;
    template<class T>
    using tmat4x3 = mat<T, 4, 3>;
    template<class T>
    using tmat4x4 = mat<T, 4, 4>;
}

#include "matrix.inl"
