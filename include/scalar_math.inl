#pragma once

#include "scalar_math.h"

#include <cmath>

#include "units.h"

#include "detail/detail.h"

namespace dla::math {
	template<std::intmax_t pNum, std::intmax_t pDen, class T>
    auto pow(const T& val) {
		using result_type = detail::power_t<T, pNum, pDen>;
		return result_type{ std::pow(float(val), float(pNum) / float(pDen)) };
    }
	template<class T>
    constexpr auto sqrt(const T& val) {
		using result_type = detail::power_t<T, 1, 2>;
        // if (std::is_constexpr_evaluated()) {
            return result_type{ detail::sqrt(float(val)) };
        // }
        // else {
        //     return result_type{ std::sqrt(float(val)) };
        // }
    }
	template<class T>
    auto cbrt(const T& val) {
		using result_type = detail::power_t<T, 1, 3>;
        return result_type{ std::cbrt(float(val)) };
    }

    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr auto abs(const base_unit<Tag, Num, Den>& val) {
        return float(val) > 0.0f ? val : -val;
    }
    template<class... Units>
    constexpr auto abs(const comp_unit<Units...>& val) {
        return float(val) > 0.0f ? val : -val;
    }
}
