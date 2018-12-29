#pragma once

#include <cmath>

#include "units.h"

#include "detail/detail.h"

// Note: Without constexpr math functions we can not make constexpr functions here either
namespace unit::math {
	template<std::intmax_t pNum, std::intmax_t pDen = 1, class T>
    auto pow(const T& val) {
		using result_type = detail::power_t<T, pNum, pDen>;
		return result_type{ std::pow(float(val), float(pNum) / float(pDen)) };
    }
	template<class T>
    auto sqrt(const T& val) {
		using result_type = detail::power_t<T, 1, 2>;
        return result_type{ std::sqrt(float(val)) };
    }
	template<class T>
    auto cbrt(const T& val) {
		using result_type = detail::power_t<T, 1, 3>;
        return result_type{ std::cbrt(float(val)) };
    }
}
