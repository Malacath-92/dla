#pragma once

#include "scalar_math.h"

#include <type_traits>

auto almost_same = [](auto&& lhs, auto&& rhs) {
    using T = std::remove_reference_t<decltype(lhs)>;
    if constexpr (std::is_integral_v<T>) {
        return lhs - rhs == T{ 0 };
    }
    else {
        return dla::math::abs(lhs - rhs) <= T{ 0.000001 };
    }
};