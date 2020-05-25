#pragma once

#include <algorithm>
#include <cstdint>
#include <string>

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
}
