#pragma once

#include <cstdint>

// TODO: Members should not be zero-initialized, not doing this causes some constexpr problems

namespace unit::detail {
    template<class T, std::size_t N>
    struct vec_elements {
        static_assert(N > 0 && N <= 5, "Vectors only supported for sizes 1, 2, 3 and 4!");
    };
    template<class T>
    struct vec_elements<T, 1> {
        constexpr vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        template<class U>
        constexpr explicit vec_elements(const vec_elements<U, 1>& val) :
            x(static_cast<T>(val.x)) {}
        
        constexpr explicit vec_elements(const T& pX) :
            x(pX) {}
        template<class U>
        constexpr explicit vec_elements(const U& val) : 
            x(static_cast<T>(val)) {}
        constexpr explicit vec_elements(T&& pX) :
            x(std::forward<decltype(pX)>(pX)) {}

        T x{};
    };
    template<class T>
    struct vec_elements<T, 2> {
        constexpr vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        template<class U>
        constexpr explicit vec_elements(const vec_elements<U, 2>& val) :
            x(static_cast<T>(val.x)),
            y(static_cast<T>(val.y)) {}
        
        template<class U>
        constexpr explicit vec_elements(const U& val) :
            x(static_cast<T>(val)),
            y(static_cast<T>(val)) {}
        constexpr vec_elements(const T& pX, const T& pY) :
            x(pX),
            y(pY) {}
        template<class U>
        constexpr vec_elements(const U& pX, const U& pY) :
            x(static_cast<T>(pX)),
            y(static_cast<T>(pY)) {}
        constexpr vec_elements(T&& pX, T&& pY) :
            x(std::forward<decltype(pX)>(pX)),
            y(std::forward<decltype(pY)>(pY)) {}
        
        T x{}, y{};
    };
    template<class T>
    struct vec_elements<T, 3> {
        constexpr vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        template<class U>
        constexpr explicit vec_elements(const vec_elements<U, 3>& val) :
            x(static_cast<T>(val.x)),
            y(static_cast<T>(val.y)),
            z(static_cast<T>(val.z)) {}

        template<class U>
        constexpr explicit vec_elements(const U& val) :
            x(static_cast<T>(val)),
            y(static_cast<T>(val)),
            z(static_cast<T>(val)) {}
        constexpr vec_elements(const T& pX, const T& pY, const T& pZ) :
            x(pX),
            y(pY),
            z(pZ) {}
        template<class U>
        constexpr vec_elements(const U& pX, const U& pY, const U& pZ) : 
            x(static_cast<T>(pX)),
            y(static_cast<T>(pY)),
            z(static_cast<T>(pZ)) {}
        constexpr vec_elements(T&& pX, T&& pY, T&& pZ) :
            x(std::forward<decltype(pX)>(pX)),
            y(std::forward<decltype(pY)>(pY)),
            z(std::forward<decltype(pZ)>(pZ)) {}
        
        T x{}, y{}, z{};
    };
    template<class T>
    struct vec_elements<T, 4> {
        constexpr vec_elements() = default;
        constexpr vec_elements(const vec_elements&) = default;
        constexpr vec_elements(vec_elements&&) = default;
        constexpr vec_elements& operator=(const vec_elements&) = default;
        constexpr vec_elements& operator=(vec_elements&&) = default;

        template<class U>
        constexpr explicit vec_elements(const vec_elements<U, 4>& val) :
            x(static_cast<T>(val.x)),
            y(static_cast<T>(val.y)),
            z(static_cast<T>(val.z)),
            w(static_cast<T>(val.w)) {}

        template<class U>
        constexpr explicit vec_elements(const U& val) :
            x(static_cast<T>(val)),
            y(static_cast<T>(val)),
            z(static_cast<T>(val)),
            w(static_cast<T>(val)) {}
        constexpr vec_elements(const T& pX, const T& pY, const T& pZ, const T& pW) :
            x(pX),
            y(pY),
            z(pZ), 
            w(pW) {}
        template<class U>
        constexpr vec_elements(const U& pX, const U& pY, const U& pZ, const U& pW) :
            x(static_cast<T>(pX)),
            y(static_cast<T>(pY)),
            z(static_cast<T>(pZ)), 
            w(static_cast<T>(pW)) {}
        constexpr vec_elements(T&& pX, T&& pY, T&& pZ, T&& pW) :
            x(std::forward<decltype(pX)>(pX)),
            y(std::forward<decltype(pY)>(pY)),
            z(std::forward<decltype(pZ)>(pZ)),
            w(std::forward<decltype(pZ)>(pW)) {}
        
        T x{}, y{}, z{}, w{};
    };
}
