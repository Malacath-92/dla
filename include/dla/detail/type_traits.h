#pragma once

#include <type_traits>

namespace dla::detail {
	template<class... T>
	struct always_false : std::false_type {};
	template<class... T>
	inline constexpr bool always_false_v = always_false<T...>::value;
}
