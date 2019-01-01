#pragma once

#include <cstdint>
#include <type_traits>
#include <ratio>
#include <string>
#include <algorithm>

namespace dla::detail {
	template<class charT>
	constexpr size_t strlen(const charT* str) {
		std::size_t size = 0;
		while(*str) {
			str++;
			size++;
		}
		return size + 1;
	}
	template<class charT, class traits = std::char_traits<charT>>
	constexpr int compare(const charT* lhs, std::size_t lhsLen,
							const charT* rhs, std::size_t rhsLen) {
#	ifdef _MSVC_LANG
		if(lhs != rhs) {
#	else
		{ // gcc and clang do not allow comparison of charT* in a constant expression
#	endif
			const int result = traits::compare(lhs, rhs, std::min(lhsLen, rhsLen));
			if(result != 0)
				return result;
		}
		if(lhsLen == rhsLen) {
			return 0;
		}
		return lhsLen < rhsLen ? -1 : 1;
	}
	template<class charT, class traits = std::char_traits<charT>>
	constexpr int compare(const charT* lhs, const charT* rhs) {
		std::size_t lhsLen = strlen(lhs);
		std::size_t rhsLen = strlen(rhs);
		return compare(lhs, lhsLen, rhs, rhsLen);
	}

	// Babylonian Method
	// Quick and dirty implementation, only run in constexpr context
	// TODO: C++20 use consteval
	constexpr int sqrt_iterations = 3;
	template<class T>
	constexpr auto sqrt(T m) {
		T i{};
		while (i * i <= m)
			i += static_cast<T>(0.1f);
		T x1 = i;
		T x2 = m;
		for (int j = 0; j < detail::sqrt_iterations; j++) {
			x2 = m;
			x2 /= x1;
			x2 += x1;
			x2 /= 2;
			x1 = x2;
		}
		return x2;
	}

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
		return accumulate(first, last, std::move(init), std::plus<>());
	}
}
