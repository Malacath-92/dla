#pragma once

#include "vector_math.h"

#include "detail/vector_elements.h"
#include "detail/vector_iterator.h"

namespace unit::vector {

#ifdef INDEXING_OPERATOR_THROWS_OUT_OF_BOUNDS
    inline constexpr bool vec_index_operator_is_noexcept = false;
#else
    inline constexpr bool vec_index_operator_is_noexcept = true;
#endif

    template<class T, std::size_t N>
    struct vec : detail::vec_elements<T, N> {
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
		using iterator = detail::vec_iterator<vec, N>;
		using const_iterator = detail::vec_iterator<const vec, N>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        static constexpr std::size_t length = N;

        using vec_elements = detail::vec_elements<T, N>;
        using vec_elements::vec_elements;
        template<class U>
        constexpr explicit vec(const vec<U, N>& val) :
            vec_elements(static_cast<const detail::vec_elements<U, N>&>(val)) {}

        constexpr const_reference operator[](std::size_t idx) const noexcept(vec_index_operator_is_noexcept) {
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
            if constexpr (!vec_index_operator_is_noexcept) {
                throw std::out_of_range("Vector index out of rance!");
            }
            declare_unreachable();
        }
        constexpr reference operator[](std::size_t idx) noexcept(vec_index_operator_is_noexcept) {
            return const_cast<reference>(static_cast<const vec*>(this)->operator[](idx));
        }

    #define MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(op) \
        template<class U> \
        constexpr decltype(auto) operator op##=(const U& rhs) noexcept { \
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
        template<class U> \
        constexpr decltype(auto) operator op##=(const vec<U, length>& rhs) noexcept { \
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

        template<class U>
        constexpr auto compare(const vec<U, N>& rhs) const {
            return vector::compare(*this, rhs);
        }

        // Conversion only for size 1 vectors
        template<std::size_t M = N, typename = std::enable_if_t<M == 1>>
        constexpr operator const_reference() const noexcept { return this->x; }
        template<std::size_t M = N, typename = std::enable_if_t<M == 1>>
        constexpr operator reference() noexcept { return this->x; }

		constexpr iterator begin() noexcept { return { *this, 0 }; }
		constexpr const_iterator begin() const noexcept { return { *this, 0 }; }
		constexpr iterator end() noexcept { return { *this, N }; }
		constexpr const_iterator end() const noexcept { return { *this, N }; }

		constexpr reverse_iterator rbegin() noexcept { return { *this, N - 1 }; }
		constexpr const_reverse_iterator rbegin() const noexcept { return { *this, N - 1 }; }
		constexpr reverse_iterator rend() noexcept { return { *this, -1 }; }
		constexpr const_reverse_iterator rend() const noexcept { return { *this, -1 }; }

		constexpr const_iterator cbegin() noexcept { return { *this, 0 }; }
		constexpr const_iterator cend() const noexcept { return { *this, N }; }
		constexpr const_reverse_iterator crbegin() noexcept { return { *this, N - 1 }; }
		constexpr const_reverse_iterator crend() noexcept { return { *this, -1 }; }
    };

    template<class T>
    using tvec1 = vec<T, 1>;
    template<class T>
    using tvec2 = vec<T, 2>;
    template<class T>
    using tvec3 = vec<T, 3>;
    template<class T>
    using tvec4 = vec<T, 4>;

    template<class T> vec(const T&, const T&) -> vec<T, 2>;
    template<class T> vec(const T&, const T&, const T&) -> vec<T, 3>;
    template<class T> vec(const T&, const T&, const T&, const T&) -> vec<T, 4>;
    template<class T> vec(T&&, T&&) -> vec<T, 2>;
    template<class T> vec(T&&, T&&, T&&) -> vec<T, 3>;
    template<class T> vec(T&&, T&&, T&&, T&&) -> vec<T, 4>;

    using vec1 = tvec1<float>;
    using vec2 = tvec2<float>;
    using vec3 = tvec3<float>;
    using vec4 = tvec4<float>;

    using dvec1 = tvec1<double>;
    using dvec2 = tvec2<double>;
    using dvec3 = tvec3<double>;
    using dvec4 = tvec4<double>;

    using ivec1 = tvec1<int32_t>;
    using ivec2 = tvec2<int32_t>;
    using ivec3 = tvec3<int32_t>;
    using ivec4 = tvec4<int32_t>;

    using uvec1 = tvec1<uint32_t>;
    using uvec2 = tvec2<uint32_t>;
    using uvec3 = tvec3<uint32_t>;
    using uvec4 = tvec4<uint32_t>;

    using bvec1 = tvec1<bool>;
    using bvec2 = tvec2<bool>;
    using bvec3 = tvec3<bool>;
    using bvec4 = tvec4<bool>;
}