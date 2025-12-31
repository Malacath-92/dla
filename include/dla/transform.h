#pragma once

#include "matrix.h"
#include "matrix_math.h"

#include "detail/vector_elements.h"
#include "detail/vector_iterator.h"

namespace dla {
    template<class T>
    using trans2 = tmat3<T>;
    template<class T>
    using trans3 = tmat4<T>;

    enum class Axis {
        X = 0,
        Y = 1,
        Z = 2,
    };

    template<class T, std::size_t N>
    constexpr auto make_translation(const vec<T, N>& v) noexcept;
    template<class T>
    constexpr auto make_rotation(T angle) noexcept;
    template<class T, Axis RotateAround>
    constexpr auto make_rotation(T angle) noexcept;
    template<class T, std::size_t N>
    constexpr auto make_scale(const vec<T, N>& s) noexcept;
}

#include "transform.inl"
