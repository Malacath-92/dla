#pragma once

#include "matrix.h"

namespace dla {
    template<class T, std::size_t N, std::size_t M>
    constexpr mat<T, N, M>::mat(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        vec_elements(col_type{val}) {}
    template<class T, std::size_t N, std::size_t M>
    template<class U>
    constexpr mat<T, N, M>::mat(const mat<U, num_row, num_col>& val) :
        vec_elements(static_cast<const detail::vec_elements<vec<U, N>, M>&>(val)) {}

    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_reference mat<T, N, M>::operator[](std::size_t idx) const noexcept(mat_index_operator_is_noexcept) {
        if (idx == 0) return this->x;
        else if constexpr (M > 1) {
            if (idx == 1) return this->y;
            else if constexpr (M > 2) {
                if (idx == 2) return this->z;
                else if constexpr (M > 3) {
                    if (idx == 3) return this->w;
                }
            }
        }
        if constexpr (!mat_index_operator_is_noexcept) {
            throw std::out_of_range("Matrix index out of rance!");
        }

#	    ifdef _MSVC_LANG
        __assume(false);
#	    else
        __builtin_unreachable();
#	    endif
    }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::reference mat<T, N, M>::operator[](std::size_t idx) noexcept(mat_index_operator_is_noexcept) {
        return const_cast<reference>(static_cast<const mat*>(this)->operator[](idx));
    }

#define MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class T, std::size_t N, std::size_t M> \
    template<class U> \
    constexpr decltype(auto) mat<T, N, M>::operator op##=(const U& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(+)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(-)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(*)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(/)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(%)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(&)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(|)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(^)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(<<)
    MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR(>>)
#undef MAKE_MATRIX_SCALAR_BINARY_ASSIGNEMT_OPERATOR

#define MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class T, std::size_t N, std::size_t M> \
    template<class U> \
    constexpr decltype(auto) mat<T, N, M>::operator op##=(const mat<U, num_row, num_col>& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(+)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(-)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(*)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(/)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(%)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(&)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(|)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(^)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(<<)
    MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR(>>)
#undef MAKE_MATRIX_MATRIX_BINARY_ASSIGNEMT_OPERATOR

    template<class T, std::size_t N, std::size_t M>
    template<class U>
    constexpr auto mat<T, N, M>::compare(const mat<U, N, M>& rhs) const {
        return dla::compare(*this, rhs);
    }

    template<class T, std::size_t N, std::size_t M>
    template<class U, size_t L>
    constexpr auto mat<T, N, M>::dot(const mat<U, M, L>& rhs) const {
        return dla::dot(*this, rhs);
    }
    template<class T, std::size_t N, std::size_t M>
    template<class U>
    constexpr auto mat<T, N, M>::dot(const vec<U, M>& rhs) const {
        return dla::dot(*this, rhs);
    }

    // Conversion only for size 1 MATRIXs
    template<class T, std::size_t N, std::size_t M>
	template<std::size_t L, typename>
    constexpr mat<T, N, M>::operator const_reference() const noexcept { return this->x; }
    template<class T, std::size_t N, std::size_t M>
	template<std::size_t L, typename>
    constexpr mat<T, N, M>::operator reference() noexcept { return this->x; }

    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::iterator mat<T, N, M>::begin() noexcept { return { *this, 0 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_iterator mat<T, N, M>::begin() const noexcept { return { *this, 0 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::iterator mat<T, N, M>::end() noexcept { return { *this, N }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_iterator mat<T, N, M>::end() const noexcept { return { *this, N }; }

    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::reverse_iterator mat<T, N, M>::rbegin() noexcept { return { *this, N - 1 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_reverse_iterator mat<T, N, M>::rbegin() const noexcept { return { *this, N - 1 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::reverse_iterator mat<T, N, M>::rend() noexcept { return { *this, -1 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_reverse_iterator mat<T, N, M>::rend() const noexcept { return { *this, -1 }; }

    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_iterator mat<T, N, M>::cbegin() noexcept { return { *this, 0 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_iterator mat<T, N, M>::cend() const noexcept { return { *this, N }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_reverse_iterator mat<T, N, M>::crbegin() noexcept { return { *this, N - 1 }; }
    template<class T, std::size_t N, std::size_t M>
    constexpr typename mat<T, N, M>::const_reverse_iterator mat<T, N, M>::crend() noexcept { return { *this, -1 }; }
}