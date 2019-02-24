#pragma once

#include <cstddef>

namespace dla {
    template<class T, std::size_t N, std::size_t M>
    struct mat;
}

namespace dla::detail {
    template<std::size_t I, class T>
    struct get_col_t;

    template<std::size_t I, class T, std::size_t M>
    struct get_col_t<I, mat<T, 1, M>> {
        constexpr auto operator()(mat<T, 1, M>& matrix) {
            using res_t = typename mat<T, 1, M>::col_type;
            res_t res{ matrix.x[I] };
            return res;
        }
        constexpr auto operator()(const mat<T, 1, M>& matrix) {
            using res_t = const typename mat<T, 1, M>::col_type;
            res_t res{ matrix.x[I] };
            return res;
        }
    };
    template<std::size_t I, class T, std::size_t M>
    struct get_col_t<I, mat<T, 2, M>> {
        constexpr auto operator()(mat<T, 2, M>& matrix) {
            using res_t = typename mat<T, 2, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I] };
            return res;
        }
        constexpr auto operator()(const mat<T, 2, M>& matrix) {
            using res_t = const typename mat<T, 2, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I] };
            return res;
        }
    };
    template<std::size_t I, class T, std::size_t M>
    struct get_col_t<I, mat<T, 3, M>> {
        constexpr auto operator()(mat<T, 3, M>& matrix) {
            using res_t = typename mat<T, 3, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I], matrix.z[I] };
            return res;
        }
        constexpr auto operator()(const mat<T, 3, M>& matrix) {
            using res_t = const typename mat<T, 3, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I], matrix.z[I] };
            return res;
        }
    };
    template<std::size_t I, class T, std::size_t M>
    struct get_col_t<I, mat<T, 4, M>> {
        constexpr auto operator()(mat<T, 4, M>& matrix) {
            using res_t = typename mat<T, 4, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I], matrix.z[I], matrix.w[I] };
            return res;
        }
        constexpr auto operator()(const mat<T, 4, M>& matrix) {
            using res_t = const typename mat<T, 4, M>::col_type;
            res_t res{ matrix.x[I], matrix.y[I], matrix.z[I], matrix.w[I] };
            return res;
        }
    };
}
