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

#define MAKE_VECTOR_UNARY_OPERATOR(op) \
    template<class T, std::size_t N> \
    constexpr auto operator op(const T& val) noexcept { \
        vector::vec<decltype(op std::declval<T>()), N> res{}; \
        auto val_it = val.begin(); \
        auto it = res.begin(); \
        const auto it_end = res.end(); \
        for (; it != it_end;) { \
            *it = op *val_it; \
            ++val_it; \
            ++it; \
        } \
        return res; \
    }
    MAKE_VECTOR_UNARY_OPERATOR(+)
    MAKE_VECTOR_UNARY_OPERATOR(-)
    MAKE_VECTOR_UNARY_OPERATOR(~)
#undef MAKE_VECTOR_UNARY_OPERATOR

    template<class T, class U, std::size_t N>
    constexpr auto operator==(const vector::vec<T, N>& lhs, const vector::vec<U, N>& rhs) noexcept {
        auto res = lhs[0] == rhs[0];
        if constexpr (N > 1) {
            auto lhs_it = lhs.begin() + 1;
            auto rhs_it = rhs.begin() + 1;
            const auto lhs_it_end = lhs.end();
            for (; lhs_it != lhs_it_end;) {
                res &= *lhs_it == *rhs_it;
                ++lhs_it;
                ++rhs_it;
            }
        }
        return res;
    }
    template<class T, class U, std::size_t N>
    constexpr auto operator!=(const vector::vec<T, N>& lhs, const vector::vec<U, N>& rhs) noexcept {
        return !(lhs == rhs);
    }

    template<class T, class U, std::size_t N>
    constexpr auto compare(const vector::vec<T, N>& lhs, const vector::vec<U, N>& rhs) noexcept {
        vector::vec<decltype(std::declval<T>() == std::declval<U>()), N> res{};
        auto lhs_it = lhs.begin();
        auto rhs_it = rhs.begin();
        auto it = res.begin();
        const auto it_end = res.end();
        for (; it != it_end;) {
            *it = *lhs_it == *rhs_it;
            ++lhs_it;
            ++rhs_it;
            ++it;
        }
        return res;
    }
}
