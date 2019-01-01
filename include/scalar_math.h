#pragma once

namespace dla {
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;
}

// Note: Without constexpr math functions we can not make constexpr functions here either
namespace dla::math {
	template<std::intmax_t pNum, std::intmax_t pDen = 1, class T>
    auto pow(const T& val);
	template<class T>
    constexpr auto sqrt(const T& val);
	template<class T>
    auto cbrt(const T& val);

    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr auto abs(const base_unit<Tag, Num, Den>& val);
    template<class... Units>
    constexpr auto abs(const comp_unit<Units...>& val);
}

#include "scalar_math.inl"
