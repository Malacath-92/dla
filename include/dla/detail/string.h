#pragma once

namespace dla::detail {
	constexpr int compare(const char* lhs, const char* rhs) {
		while (*lhs != '\0' && *lhs == *rhs) {
			lhs++;
			rhs++;
		}
		return static_cast<const unsigned char>(*lhs) - static_cast<const unsigned char>(*rhs);
	}
}
