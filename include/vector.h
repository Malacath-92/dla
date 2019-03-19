#pragma once

#include <stdexcept>
#include <cstddef>
#include <type_traits>

#include "vector_math.h"

#include "detail/vector_elements.h"
#include "detail/vector_iterator.h"

namespace dla {
#ifdef INDEXING_OPERATOR_THROWS_OUT_OF_BOUNDS
    inline constexpr bool vec_index_operator_is_noexcept = false;
#else
    inline constexpr bool vec_index_operator_is_noexcept = true;
#endif

    template<class T, std::size_t N>
    struct vec : detail::vec_elements<T, N> {
        using value_type = std::remove_reference_t<T>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
		using iterator = detail::vec_iterator<vec, N>;
		using const_iterator = detail::vec_iterator<const vec, N>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        static constexpr std::size_t size = N;

        vec() = default;
        using vec_elements = detail::vec_elements<T, N>;
        using vec_elements::vec_elements;
        using vec_elements::operator=;
        template<class U>
        constexpr explicit vec(const vec<U, N>& val);

        constexpr const_reference operator[](std::size_t idx) const noexcept(vec_index_operator_is_noexcept);
        constexpr reference operator[](std::size_t idx) noexcept(vec_index_operator_is_noexcept);

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
        constexpr decltype(auto) operator+=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator-=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator*=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator/=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator%=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator&=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator|=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator^=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator<<=(const vec<U, size>& rhs) noexcept;
        template<class U>
        constexpr decltype(auto) operator>>=(const vec<U, size>& rhs) noexcept;

        template<class U>
        constexpr auto compare(const vec<U, N>& rhs) const;
        template<class U, class Distance = distances::euclidean<T, U>>
        DLA_OPTIMISTIC_CONSTEXPR auto distance(const vec<U, size>& rhs, Distance&& metric = {}) const;
        template<class Distance = distances::euclidean<T>>
        DLA_OPTIMISTIC_CONSTEXPR auto length(Distance&& metric = {}) const;
        template<class U>
        constexpr auto dot(const vec<U, N>& rhs) const;

        // Conversion only for size 1 vectors
        template<std::size_t M = N, typename = std::enable_if_t<M == 1>>
        constexpr operator const_reference() const noexcept;
        template<std::size_t M = N, typename = std::enable_if_t<M == 1>>
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

#include "vector.inl"
