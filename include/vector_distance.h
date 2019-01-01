#pragma once

#include <cmath>

#include "detail/detail.h"
#include "scalar_math.h"

namespace dla {
    template<class T, std::size_t N>
    struct vec;

	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;
}

namespace dla::distances {
    template<class T, class U = T>
    struct euclidean {
        template<std::size_t N>
        constexpr auto operator()(const vec<T, N>& lhs, const vec<U, N>& rhs) {
            const auto diff = lhs - rhs;
            const auto diff_sqr = diff * diff;
            using diff_sqr_type = typename std::decay_t<decltype(diff_sqr)>::value_type;
            const auto diff_sqr_sum = detail::accumulate(diff_sqr.begin(), diff_sqr.end(), diff_sqr_type{});
            return detail::sqrt(diff_sqr_sum);
        }
    };
    template<class T, class U = T>
    struct manhattan {
        template<std::size_t N>
        constexpr auto operator()(const vec<T, N>& lhs, const vec<U, N>& rhs) {
            const auto diff = lhs - rhs; // TODO: Use abs here
            using diff_type = typename std::decay_t<decltype(diff)>::value_type;
            return detail::accumulate(diff.begin(), diff.end(), diff_type{}, [](diff_type&& lhs, const diff_type& rhs){
                lhs += rhs > diff_type{ 0.0f } ? rhs : -rhs;
                return lhs;
            }); // TODO: Don't specify predicate when abs available
        }
    };

    // Specialization for units
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    struct euclidean<base_unit<Tag, Num, Den>> {
        using unit = base_unit<Tag, Num, Den>;
        template<std::size_t N>
        constexpr auto operator()(const vec<unit, N>& lhs, const vec<unit, N>& rhs) {
            const auto diff = lhs - rhs;
            const auto diff_sqr = diff * diff;
            using diff_sqr_type = typename std::decay_t<decltype(diff_sqr)>::value_type;
            const auto diff_sqr_sum = detail::accumulate(diff_sqr.begin(), diff_sqr.end(), diff_sqr_type{});
            return math::sqrt(diff_sqr_sum);
        }
    };
    template<class... Units>
    struct euclidean<comp_unit<Units...>> {
        using unit = comp_unit<Units...>;
        template<std::size_t N>
        constexpr auto operator()(const vec<unit, N>& lhs, const vec<unit, N>& rhs) {
            const auto diff = lhs - rhs;
            const auto diff_sqr = diff * diff;
            using diff_sqr_type = typename std::decay_t<decltype(diff_sqr)>::value_type;
            const auto diff_sqr_sum = detail::accumulate(diff_sqr.begin(), diff_sqr.end(), diff_sqr_type{});
            return math::sqrt(diff_sqr_sum);
        }
    };
}

