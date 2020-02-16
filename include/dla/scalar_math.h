#pragma once

#include "detail/detail.h"

#include <cstdint>

namespace dla::math {
	template<std::intmax_t pNum, std::intmax_t pDen = 1, class T>
    DLA_OPTIMISTIC_CONSTEXPR auto pow(const T& val);
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto sqrt(const T& val);
	template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto cbrt(const T& val);

    template<class T>
    constexpr auto abs(const T& val);

    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto floor(const T& val);
    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto ceil(const T& val);
    template<class T>
    DLA_OPTIMISTIC_CONSTEXPR auto round(const T& val);
}

#include "scalar_math.inl"
