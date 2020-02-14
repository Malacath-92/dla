#pragma once

#include "vector_math.h"

#include <cmath>

namespace dla {
#define MAKE_VECTOR_VECTOR_BINARY_OPERATOR(op) \
    template<class T, class U, std::size_t N> \
    constexpr auto operator op(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept { \
        vec<decltype(std::declval<T>() op std::declval<U>()), N> res{}; \
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
    template<class T, class U, std::size_t N, typename> \
    constexpr auto operator op(const vec<T, N>& lhs, const U& rhs) noexcept { \
        using res_t = vec<decltype(std::declval<T>() op std::declval<U>()), N>; \
        res_t res{}; \
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
    template<class T, class U, std::size_t N, typename> \
    constexpr auto operator op(const T& lhs, const vec<U, N>& rhs) noexcept { \
        using res_t = vec<decltype(std::declval<T>() op std::declval<U>()), N>; \
        res_t res{}; \
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
    constexpr auto operator op(const vec<T, N>& val) noexcept { \
        using res_t = vec<decltype(op std::declval<T>()), N>; \
        res_t res{}; \
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
    constexpr auto operator==(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept {
        if (lhs[0] != rhs[0]) {
            return false;
        }
        if constexpr (N > 1) {
            auto lhs_it = lhs.begin() + 1;
            auto rhs_it = rhs.begin() + 1;
            const auto lhs_it_end = lhs.end();
            for (; lhs_it != lhs_it_end;) {
                if (*lhs_it != *rhs_it) {
                    return false;
                }
                ++lhs_it;
                ++rhs_it;
            }
        }
        return true;
    }
    template<class T, class U, std::size_t N>
    constexpr auto operator!=(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept {
        return !(lhs == rhs);
    }

    template<class T, class U, std::size_t N>
    constexpr auto compare(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept {
        using res_t = vec<decltype(std::declval<T>() == std::declval<U>()), N>;
        res_t res{};
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

    template<class T, std::size_t N>
    constexpr auto abs(const vec<T, N>& val) noexcept {
        using res_t = vec<T, N>;
        res_t res{};
        auto val_it = val.begin();
        auto it = res.begin();
        const auto it_end = res.end();
        for (; it != it_end;) {
            *it = math::abs(*val_it);
            ++val_it;
            ++it;
        }
        return res;
    }

    template<class T, class U, std::size_t N, class Distance>
    DLA_OPTIMISTIC_CONSTEXPR auto distance(const vec<T, N>& lhs, const vec<U, N>& rhs, Distance&& metric) noexcept {
        return metric(lhs, rhs);
    }
    template<class T, std::size_t N, class Distance>
    DLA_OPTIMISTIC_CONSTEXPR auto length(const vec<T, N>& val, Distance&& metric) noexcept {
        constexpr vec<T, N> zero{};
        return distance(val, zero, std::move(metric));
    }

    template<class T, class U, std::size_t N>
    constexpr auto dot(const vec<T, N>& lhs, const vec<U, N>& rhs) {
        using res_t = decltype(std::declval<T>() * std::declval<U>());
        res_t res{};
        auto lhs_it = lhs.begin();
        auto rhs_it = rhs.begin();
        const auto lhs_it_end = lhs.end();
        for (; lhs_it != lhs_it_end;) {
            res += *lhs_it * *rhs_it;
            ++lhs_it;
            ++rhs_it;
        }
        return res;
    }
}
