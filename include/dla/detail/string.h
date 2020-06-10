#pragma once

namespace dla::detail {
	constexpr int compare(const char* lhs, const char* rhs) {
		while (*lhs != '\0' && *lhs == *rhs) {
			lhs++;
			rhs++;
		}
		return static_cast<int>(*lhs) - static_cast<int>(*rhs);
	}
}
