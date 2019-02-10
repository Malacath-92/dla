#pragma once

#include <cstdint>
#include <type_traits>

// Note: Default constructors are not declared constexpr to allow
//          - zero-initialization of constexpr variables
//          - uninitialized memory at runtime for better performance

namespace dla::detail {
    template<class T, std::size_t N>
    struct vec_elements {
        static_assert(N > 0 && N <= 5, "Vectors only supported for sizes 1, 2, 3 and 4!");
    };
    template<class T>
    struct vec_elements<T, 1> {
        vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        constexpr explicit vec_elements(const T& px) noexcept(std::is_nothrow_copy_constructible_v<T>);
        
        constexpr explicit vec_elements(T&& px) noexcept(std::is_nothrow_move_constructible_v<T>);

        template<class U, typename = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 1>& val);

        union { T x, r, s; };
    };
    template<class T>
    struct vec_elements<T, 2> {
        vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;
        
        constexpr explicit vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>);
        
        constexpr vec_elements(const T& px, const T& py) noexcept(std::is_nothrow_copy_constructible_v<T>);

        constexpr vec_elements(T&& px, T&& py) noexcept(std::is_nothrow_move_constructible_v<T>);

        template<class U, typename = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 2>& val);
        
        union { T x, r, s; };
        union { T y, g, t; };
    };
    template<class T>
    struct vec_elements<T, 3> {
        vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;
        
        constexpr explicit vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>);
        
        constexpr vec_elements(const T& px, const T& py, const T& pz) noexcept(std::is_nothrow_copy_constructible_v<T>);

        constexpr vec_elements(T&& px, T&& py, T&& pz) noexcept(std::is_nothrow_move_constructible_v<T>);

        template<class U, typename = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 3>& val);
        
        union { T x, r, s; };
        union { T y, g, t; };
        union { T z, b, p; };
    };
    template<class T>
    struct vec_elements<T, 4> {
        vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        constexpr explicit vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>);
        
        constexpr vec_elements(const T& px, const T& py, const T& pz, const T& pw) noexcept(std::is_nothrow_copy_constructible_v<T>);

        constexpr vec_elements(T&& px, T&& py, T&& pz, T&& pw) noexcept(std::is_nothrow_move_constructible_v<T>);

        template<class U, typename = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 4>& val);
        
        union { T x, r, s; };
        union { T y, g, t; };
        union { T z, b, p; };
        union { T w, a, q; };
    };
}

#include "vector_elements.inl"
