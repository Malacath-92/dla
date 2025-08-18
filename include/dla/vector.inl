#pragma once

#include "vector.h"

#include "detail/defines.h"

namespace dla {
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_reference vec<T, N>::operator[](std::size_t idx) const noexcept(vec_index_operator_is_noexcept) {
        if (idx == 0) return this->x;
        else if constexpr (N > 1) {
            if (idx == 1) return this->y;
            else if constexpr (N > 2) {
                if (idx == 2) return this->z;
                else if constexpr (N > 3) {
                    if (idx == 3) return this->w;
                }
            }
        }
        
#if DLA_VEC_INDEX_OPERATOR_IS_NOEXCEPT
        declare_unreachable();
#else
        throw std::out_of_range("Vector index out of rance!");
#endif
    }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::reference vec<T, N>::operator[](std::size_t idx) noexcept(vec_index_operator_is_noexcept) {
        return const_cast<reference>(static_cast<const vec*>(this)->operator[](idx));
    }

#define MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class T, std::size_t N> \
    template<class U> \
    constexpr decltype(auto) vec<T, N>::operator op##=(const U& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(+)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(-)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(*)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(/)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(%)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(&)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(|)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(^)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(<<)
    MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(>>)
#undef MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR

#define MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class T, std::size_t N> \
    template<class U> \
    constexpr decltype(auto) vec<T, N>::operator op##=(const vec<U, size>& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(+)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(-)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(*)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(/)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(%)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(&)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(|)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(^)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(<<)
    MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(>>)
#undef MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR

    template<class T, std::size_t N>
    template<class U>
    constexpr auto vec<T, N>::compare(const vec<U, N>& rhs) const {
        return dla::compare(*this, rhs);
    }
    template<class T, std::size_t N>
    template<class U, class Distance>
    DLA_OPTIMISTIC_CONSTEXPR auto vec<T, N>::distance(const vec<U, size>& rhs, Distance&& metric) const {
        return dla::distance(*this, rhs, std::move(metric));
    }
    template<class T, std::size_t N>
    template<class Distance>
    DLA_OPTIMISTIC_CONSTEXPR auto vec<T, N>::length(Distance&& metric) const {
        return dla::length(*this, std::move(metric));
    }
    template<class T, std::size_t N>
    template<class U>
    constexpr auto vec<T, N>::dot(const vec<U, N>& rhs) const {
        return dla::dot(*this, rhs);
    }

    // Conversion only for size 1 vectors
    template<class T, std::size_t N>
	template<std::size_t M, typename>
    constexpr vec<T, N>::operator const_reference() const noexcept { return this->x; }
    template<class T, std::size_t N>
	template<std::size_t M, typename>
    constexpr vec<T, N>::operator reference() noexcept { return this->x; }

    // Decay only for vectors of references
    template<class T, std::size_t N>
    template<class U, typename>
    constexpr vec<U, N> vec<T, N>::decay() const {
        return vec<U, N>{ *this };
    }

    template<class T, std::size_t N>
    constexpr typename vec<T, N>::iterator vec<T, N>::begin() noexcept { return { *this, 0 }; }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_iterator vec<T, N>::begin() const noexcept { return { *this, 0 }; }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::iterator vec<T, N>::end() noexcept { return { *this, N }; }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_iterator vec<T, N>::end() const noexcept { return { *this, N }; }

    template<class T, std::size_t N>
    constexpr typename vec<T, N>::reverse_iterator vec<T, N>::rbegin() noexcept { return std::make_reverse_iterator(iterator{ *this, N }); }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_reverse_iterator vec<T, N>::rbegin() const noexcept { return std::make_reverse_iterator(const_iterator{ *this, N }); }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::reverse_iterator vec<T, N>::rend() noexcept { return std::make_reverse_iterator(iterator{ *this, 0 }); }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_reverse_iterator vec<T, N>::rend() const noexcept { return std::make_reverse_iterator(const_iterator{ *this, 0 }); }

    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_iterator vec<T, N>::cbegin() const noexcept { return { *this, 0 }; }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_iterator vec<T, N>::cend() const noexcept { return { *this, N }; }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_reverse_iterator vec<T, N>::crbegin() const noexcept { return std::make_reverse_iterator(const_iterator{ *this, N }); }
    template<class T, std::size_t N>
    constexpr typename vec<T, N>::const_reverse_iterator vec<T, N>::crend() const noexcept { return std::make_reverse_iterator(const_iterator{ *this, 0 }); }
}