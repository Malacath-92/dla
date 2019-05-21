#pragma once

#include "utility.h"

namespace dla {
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;

    template<class T, std::size_t N>
    struct vec;
    template<class T, std::size_t N, std::size_t M>
    struct mat;

	template<class Tag, std::intmax_t Num, std::intmax_t Den>
    struct is_packed<base_unit<Tag, Num, Den>> {
        static constexpr bool value = sizeof(base_unit<Tag, Num, Den>) == sizeof(float);
    };
	template<class... Units>
    struct is_packed<comp_unit<Units...>> {
        static constexpr bool value = sizeof(comp_unit<Units...>) == sizeof(float);
    };
    
    template<class T, std::size_t N>
    struct is_packed<vec<T, N>> {
        static constexpr bool value = sizeof(vec<T, N>) == sizeof(T) * N;
    };
    template<class T, std::size_t N, std::size_t M>
    struct is_packed<mat<T, N, M>> {
        static constexpr bool value = sizeof(mat<T, N, M>) == sizeof(T) * N * M;
    };
}
