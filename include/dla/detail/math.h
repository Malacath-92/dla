#pragma once

#include <cstdint>
#include <type_traits>
#include <algorithm>

namespace dla::detail {
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
}
