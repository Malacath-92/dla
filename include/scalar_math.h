#pragma once

// Note: Without constexpr math functions we can not make constexpr functions here either
namespace unit::math {
	template<std::intmax_t pNum, std::intmax_t pDen = 1, class T>
    auto pow(const T& val);
	template<class T>
    auto sqrt(const T& val);
	template<class T>
    auto cbrt(const T& val);
}

#include "scalar_math.inl"
