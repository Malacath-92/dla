#pragma once

#include <cmath>

#include "units.h"
#include "detail.h"

namespace unit::vector {
    template<class T, std::size_t N>
    struct vec;

#define MAKE_VECTOR_VECTOR_BINARY_OPERATOR(op) \
    template<class T, class U, std::size_t N> \
    constexpr auto operator op(const vector::vec<T, N>& lhs, const vector::vec<U, N>& rhs) noexcept { \
        vector::vec<decltype(std::declval<T>() op std::declval<U>()), N> res{}; \
        auto lhs_it = lhs.begin(); \
        auto rhs_it = rhs.begin(); \
        auto it = res.begin(); \
        const auto it_end = res.end(); \
        for (; it != it_end;) { \
            *it = *lhs_it op *rhs_it; \
            ++lhs_it; \
            ++rhs_it; \
            ++it; \
        } \
        return res; \
    }
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(+)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(-)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(*)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(/)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(%)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(&)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(|)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(^)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(<<)
    MAKE_VECTOR_VECTOR_BINARY_OPERATOR(>>)
#undef MAKE_VECTOR_VECTOR_BINARY_OPERATOR

#define MAKE_VECTOR_SCALAR_BINARY_OPERATOR(op) \
    template<class T, class U, std::size_t N> \
    constexpr auto operator op(const vector::vec<T, N>& lhs, const U& rhs) noexcept { \
        vector::vec<decltype(std::declval<T>() op std::declval<U>()), N> res{}; \
        auto lhs_it = lhs.begin(); \
        auto it = res.begin(); \
        const auto it_end = res.end(); \
        for (; it != it_end;) { \
            *it = *lhs_it op rhs; \
            ++lhs_it; \
            ++it; \
        } \
        return res; \
    }
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(+)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(-)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(*)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(/)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(%)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(&)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(|)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(^)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(<<)
    MAKE_VECTOR_SCALAR_BINARY_OPERATOR(>>)
#undef MAKE_VECTOR_SCALAR_BINARY_OPERATOR

#define MAKE_SCALAR_VECTOR_BINARY_OPERATOR(op) \
    template<class T, class U, std::size_t N> \
    constexpr auto operator op(const T& lhs, const vector::vec<U, N>& rhs) noexcept { \
        vector::vec<decltype(std::declval<T>() op std::declval<U>()), N> res{}; \
        auto rhs_it = rhs.begin(); \
        auto it = res.begin(); \
        const auto it_end = res.end(); \
        for (; it != it_end;) { \
            *it = lhs op *rhs_it; \
            ++rhs_it; \
            ++it; \
        } \
        return res; \
    }
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(+)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(-)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(*)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(/)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(%)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(&)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(|)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(^)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(<<)
    MAKE_SCALAR_VECTOR_BINARY_OPERATOR(>>)
#undef MAKE_SCALAR_VECTOR_BINARY_OPERATOR
}
