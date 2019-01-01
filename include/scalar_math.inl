#pragma once

#include "scalar_math.h"

#include <cmath>

#include "units.h"

#include "detail/detail.h"

namespace dla::math {
    namespace custom {
        template<std::intmax_t pNum, std::intmax_t pDen, class T>
        struct pow_impl {
            constexpr auto operator()(const T& val) {
                using result_type = detail::power_t<T, pNum, pDen>;
                // TODO: constexpr version of pow
                return result_type{ std::pow(float(val), float(pNum) / float(pDen)) };
            }
        };
        template<class T>
        struct sqrt_impl {
            constexpr auto operator()(const T& val) {
                using result_type = detail::power_t<T, 1, 2>;
                // if (std::is_constexpr_evaluated()) {
                    return result_type{ detail::sqrt(float(val)) };
                // }
                // else {
                //     return result_type{ std::sqrt(float(val)) };
                // }
            }
        };
        template<class T>
        struct cbrt_impl {
            constexpr auto operator()(const T& val) {
                using result_type = detail::power_t<T, 1, 3>;
                // if (std::is_constexpr_evaluated()) {
                    return result_type{ detail::cbrt(float(val)) };
                // }
                // else {
                //     return result_type{ std::cbrt(float(val)) };
                // }
            }
        };
        template<class T>
        struct abs_impl {
            constexpr auto operator()(const T& val) {
                return val > T{} ? val : -val;
            }
        };
    }

	template<std::intmax_t pNum, std::intmax_t pDen, class T>
    constexpr auto pow(const T& val) {
        return custom::pow_impl<pNum, pDen, T>{}(val);
    }
	template<class T>
    constexpr auto sqrt(const T& val) {
        return custom::sqrt_impl<T>{}(val);
    }
	template<class T>
    constexpr auto cbrt(const T& val) {
        return custom::cbrt_impl<T>{}(val);
    }

    template<class T>
    constexpr auto abs(const T& val) {
        return custom::abs_impl<T>{}(val);
    }
}
