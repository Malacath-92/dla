#pragma once

#include <cstdint>
#include <type_traits>

// Note: Default constructors are not declared constexpr to allow
//          - zero-initialization of constexpr variables
//          - uninitialized memory at runtime for better performance

namespace dla {
    struct init_coord_t {};
    struct init_color_t {};
    struct init_tex_t {};
}

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
        
        constexpr explicit vec_elements(const T& px, init_coord_t = {});
        constexpr explicit vec_elements(const T& pr, init_color_t);
        constexpr explicit vec_elements(const T& ps, init_tex_t);

        constexpr explicit vec_elements(T&& px, init_coord_t = {});
        constexpr explicit vec_elements(T&& pr, init_color_t);
        constexpr explicit vec_elements(T&& ps, init_tex_t);

        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 1>& val, init_coord_t = {});
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 1>& val, init_color_t);
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 1>& val, init_tex_t);

        union { T x, r, s; };
    };
    template<class T>
    struct vec_elements<T, 2> {
        vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;
        
        constexpr explicit vec_elements(const T& val);
        
        constexpr vec_elements(const T& val, init_coord_t);
        constexpr vec_elements(const T& val, init_color_t);
        constexpr vec_elements(const T& val, init_tex_t);
        
        constexpr vec_elements(const T& px, const T& py, init_coord_t = {});
        constexpr vec_elements(const T& pr, const T& pg, init_color_t);
        constexpr vec_elements(const T& ps, const T& pt, init_tex_t);

        constexpr vec_elements(T&& px, T&& py, init_coord_t = {});
        constexpr vec_elements(T&& pr, T&& pg, init_color_t);
        constexpr vec_elements(T&& ps, T&& pt, init_tex_t);

        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 2>& val, init_coord_t = {});
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 2>& val, init_color_t);
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 2>& val, init_tex_t);
        
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
        
        constexpr explicit vec_elements(const T& val);
        
        constexpr vec_elements(const T& val, init_coord_t);
        constexpr vec_elements(const T& val, init_color_t);
        constexpr vec_elements(const T& val, init_tex_t);
        
        constexpr vec_elements(const T& px, const T& py, const T& pz, init_coord_t = {});
        constexpr vec_elements(const T& pr, const T& pg, const T& pb, init_color_t);
        constexpr vec_elements(const T& ps, const T& pt, const T& pp, init_tex_t);

        constexpr vec_elements(T&& px, T&& py, T&& pz, init_coord_t = {});
        constexpr vec_elements(T&& pr, T&& pg, T&& pb, init_color_t);
        constexpr vec_elements(T&& ps, T&& pt, T&& pp, init_tex_t);

        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 3>& val, init_coord_t = {});
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 3>& val, init_color_t);
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 3>& val, init_tex_t);
        
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

        constexpr explicit vec_elements(const T& val);

        constexpr vec_elements(const T& val, init_coord_t);
        constexpr vec_elements(const T& val, init_color_t);
        constexpr vec_elements(const T& val, init_tex_t);
        
        constexpr vec_elements(const T& px, const T& py, const T& pz, const T& pw, init_coord_t = {});
        constexpr vec_elements(const T& pr, const T& pg, const T& pb, const T& pa, init_color_t);
        constexpr vec_elements(const T& ps, const T& pt, const T& pp, const T& pq, init_tex_t);

        constexpr vec_elements(T&& px, T&& py, T&& pz, T&& pw, init_coord_t = {});
        constexpr vec_elements(T&& pr, T&& pg, T&& pb, T&& pa, init_color_t);
        constexpr vec_elements(T&& ps, T&& pt, T&& pp, T&& pq, init_tex_t);

        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr explicit vec_elements(const vec_elements<U, 4>& val, init_coord_t = {});
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 4>& val, init_color_t);
        template<class U, class = std::enable_if_t<std::is_convertible_v<U, T>>>
        constexpr vec_elements(const vec_elements<U, 4>& val, init_tex_t);
        
        union { T x, r, s; };
        union { T y, g, t; };
        union { T z, b, p; };
        union { T w, a, q; };
    };
}

#include "vector_elements.inl"
