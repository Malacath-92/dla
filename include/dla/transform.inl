#pragma once

#include "transform.h"

namespace dla {
    template<class T, std::size_t N>
    constexpr auto make_translation(const vec<T, N>& v) noexcept
    {
        using trans_t = mat<T, N + 1, N + 1>;
        auto trans{ trans_t::identity() };

        auto translation{ trans.get_col(N) };
        for (std::size_t i = 0; i < N; ++i)
        {
            translation[i] = v[i];
        }

        return trans;
    }

    template<class T>
    constexpr auto make_rotation(T angle) noexcept
    {
        using trans_t = mat<T, 3, 3>;
        auto trans{ trans_t::identity() };

        const auto sin_angle = std::sin(angle);
        const auto cos_angle = std::cos(angle);

        trans[0][0] = cos_angle;
        trans[1][0] = sin_angle;
        trans[0][1] = -sin_angle;
        trans[1][1] = cos_angle;

        return trans;
    }

    template<class T, Axis RotateAround>
    constexpr auto make_rotation(T angle) noexcept
    {
        using trans_t = mat<T, 4, 4>;
        auto trans{ trans_t::identity() };

        const auto sin_angle = std::sin(angle);
        const auto cos_angle = std::cos(angle);

        if constexpr (RotateAround == Axis::X)
        {
            trans[1][1] = cos_angle;
            trans[2][1] = sin_angle;
            trans[1][2] = -sin_angle;
            trans[2][2] = cos_angle;
        }
        else if constexpr (RotateAround == Axis::Y)
        {
            trans[0][0] = cos_angle;
            trans[2][0] = sin_angle;
            trans[0][2] = -sin_angle;
            trans[2][2] = cos_angle;
        }
        else if constexpr (RotateAround == Axis::Z)
        {
            trans[0][0] = cos_angle;
            trans[1][0] = sin_angle;
            trans[0][1] = -sin_angle;
            trans[1][1] = cos_angle;
        }

        return trans;
    }

    template<class T, std::size_t N>
    constexpr auto make_scale(const vec<T, N>& s) noexcept
    {
        using trans_t = mat<T, N + 1, N + 1>;
        auto trans{ trans_t::identity() };

        for (size_t i = 0; i < N; ++i)
        {
            trans[i][i] = s[i];
        }

        return trans;
    }
}
