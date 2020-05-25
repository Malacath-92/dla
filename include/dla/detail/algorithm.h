#pragma once

#include <functional>
#include <type_traits>

namespace dla::detail {
	template<class InputIt, class T, class F>
	constexpr T accumulate(InputIt first, const InputIt last, T&& init, F&& reduce) {
		while (first != last) {
			init = reduce(std::move(init), *first);
			++first;
		}
		return std::move(init);
	}
	template<class InputIt, class T>
	constexpr T accumulate(InputIt first, const InputIt last, T&& init) {
		return dla::detail::accumulate(first, last, std::move(init), std::plus<>());
	}
}
