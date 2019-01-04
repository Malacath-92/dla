#pragma once

namespace dla {
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;
}

namespace dla::math {
	template<std::intmax_t pNum, std::intmax_t pDen = 1, class T>
    DLA_OPTIMISTIC_CONSTEXPR auto pow(const T& val);
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto sqrt(const T& val);
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto cbrt(const T& val);

    template<class T>
    constexpr auto abs(const T& val);
}

#include "scalar_math.inl"
