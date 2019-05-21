#pragma once

namespace dla {
    template<class T>
    struct is_packed;
    template<class T>
    inline constexpr auto is_packed_v = is_packed<T>::value;
}

#include "utility.inl"
