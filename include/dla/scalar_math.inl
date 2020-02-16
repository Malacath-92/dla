#pragma once

#include "scalar_math.h"

#include <cmath>

#include "units.h"

#include "detail/detail.h"

namespace dla::math {
    namespace custom {
        template<class T>
        struct zero {
            static constexpr auto value = T{};
        };
        template<class T>
        inline constexpr auto zero_v = zero<T>::value;

        template<std::intmax_t pNum, std::intmax_t pDen, class T>
        struct pow_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // TODO: constexpr version of pow
                if constexpr (is_unit_type_v<T>) {
                    using result_type = detail::power_t<T, pNum, pDen>;
                    return result_type{ std::pow(float(val), float(pNum) / float(pDen)) };
                }
                else {
                    return std::pow(val, float(pNum) / float(pDen));
                }
            }
        };
        template<class T>
        struct sqrt_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // TODO: C++20 chose constexpr version when evaluated in constant context
                // if (std::is_constant_evaluated()) {
                //     if constexpr (is_unit_type_v<T>) {
                //         using result_type = detail::power_t<T, 1, 2>;
                //         return result_type{ detail::sqrt(float(val)) };
                //     }
                //     else {
                //         return detail::sqrt(val);
                //     }
                // }
                // else {
                    if constexpr (is_unit_type_v<T>) {
                        using result_type = detail::power_t<T, 1, 2>;
                        return result_type{ std::sqrt(float(val)) };
                    }
                    else {
                        return std::sqrt(val);
                    }
                // }
            }
        };
        template<class T>
        struct cbrt_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // TODO: C++20 chose constexpr version when evaluated in constant context
                // if (std::is_constant_evaluated()) {
                //     if constexpr (is_unit_type_v<T>) {
                //         using result_type = detail::power_t<T, 1, 3>;
                //         return result_type{ detail::cbrt(float(val)) };
                //     }
                //     else {
                //         return detail::cbrt(val);
                //     }
                // }
                // else {
                    if constexpr (is_unit_type_v<T>) {
                        using result_type = detail::power_t<T, 1, 3>;
                        return result_type{ std::cbrt(float(val)) };
                    }
                    else {
                        return std::cbrt(val);
                    }
                // }
            }
        };
        template<class T>
        struct abs_impl {
            static constexpr auto call(const T& val) {
                return val > zero_v<T> ? val : -val;
            }
        };
        template<class T>
        struct floor_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // if (std::is_constant_evaluated()) {
                //     if constexpr (is_unit_type_v<T>) {
                //         return T{ detail::floor(float(val)) };
                //     }
                //     else {
                //         return detail::floor(val);
                //     }
                // }
                // else {
                    if constexpr (is_unit_type_v<T>) {
                        return T{ std::floor(float(val)) };
                    }
                    else {
                        return std::floor(val);
                    }
                // }
            }
        };
        template<class T>
        struct ceil_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // if (std::is_constant_evaluated()) {
                //     if constexpr (is_unit_type_v<T>) {
                //         return T{ detail::ceil(float(val)) };
                //     }
                //     else {
                //         return detail::ceil(val);
                //     }
                // }
                // else {
                    if constexpr (is_unit_type_v<T>) {
                        return T{ std::ceil(float(val)) };
                    }
                    else {
                        return std::ceil(val);
                    }
                // }
            }
        };
        template<class T>
        struct round_impl {
            static DLA_OPTIMISTIC_CONSTEXPR auto call(const T& val) {
                // if (std::is_constant_evaluated()) {
                //     if constexpr (is_unit_type_v<T>) {
                //         return T{ detail::round(float(val)) };
                //     }
                //     else {
                //         return detail::round(val);
                //     }
                // }
                // else {
                    if constexpr (is_unit_type_v<T>) {
                        return T{ std::round(float(val)) };
                    }
                    else {
                        return std::round(val);
                    }
                // }
            }
        };
    }

	template<std::intmax_t pNum, std::intmax_t pDen, class T>
    DLA_OPTIMISTIC_CONSTEXPR auto pow(const T& val) {
        return custom::pow_impl<pNum, pDen, T>::call(val);
    }
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto sqrt(const T& val) {
        return custom::sqrt_impl<T>::call(val);
    }
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto cbrt(const T& val) {
        return custom::cbrt_impl<T>::call(val);
    }

    template<class T>
    constexpr auto abs(const T& val) {
        return custom::abs_impl<T>::call(val);
    }

    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto floor(const T& val) {
        return custom::floor_impl<T>::call(val);
    }
    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto ceil(const T& val) {
        return custom::ceil_impl<T>::call(val);
    }
    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto round(const T& val) {
        return custom::round_impl<T>::call(val);
    }
}
