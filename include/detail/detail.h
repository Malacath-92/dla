#pragma once

#include <cstdint>
#include <type_traits>
#include <ratio>
#include <string>
#include <algorithm>

#include "tuple_sort.h"
#include "tuple_index.h"

#ifndef declare_unreachable
#	ifdef _MSVC_LANG
#		define declare_unreachable() __assume(false)
#	else
#		define declare_unreachable() __builtin_unreachable()
#	endif
#endif

namespace unit::detail {
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
}
