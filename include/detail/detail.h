#pragma once

#include <cstdint>
#include <type_traits>
#include <ratio>
#include <string>
#include <algorithm>

// Note: Functions marked optimistic constexpr can not portably be evaluated in a constant expression
#define DLA_OPTIMISTIC_CONSTEXPR constexpr

namespace dla::detail {
	template<class... T>
	struct always_false : std::false_type {};
	template<class... T>
	inline constexpr bool always_false_v = always_false<T...>::value;

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
		{
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
	
	// Quick and dirty implementation, only run in constexpr context
	// TODO: C++20 use consteval
	// TODO: C++20 use std::bit_cast and other tricks for more efficient solutions
	// Babylonian Method
	constexpr int sqrt_iterations = 3;
	template<class T>
	constexpr auto sqrt(T m) {
		T x1{};
		{
			const T guess_prec = m / 20.0f;
			while (x1 * x1 <= m)
				x1 += guess_prec;
		}
		T x2{};
		for (int j = 0; j < detail::sqrt_iterations; j++) {
			x2 = m;
			x2 /= x1;
			x2 += x1;
			x2 /= 2;
			x1 = x2;
		}
		return x2;
	}
	// Halley's Method
	constexpr int cbrt_iterations = 9;
	template<class T>
	constexpr auto cbrt(T m) {
		T x1{};
		{
			const T guess_prec = m / 50.0f;
			while (x1 * x1 <= m)
				x1 += guess_prec;
		}
		T x2{};
		for (int j = 0; j < detail::cbrt_iterations; j++) {
			x2 = x1 * x1 * x1 + 2.0f * m;
			x2 /= 2.0f * x1 * x1 * x1 + m;
			x2 *= x1;
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
