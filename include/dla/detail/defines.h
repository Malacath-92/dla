#pragma once

#ifdef _MSVC_LANG
#   define declare_unreachable() __assume(false)
#else
#   define declare_unreachable() __builtin_unreachable()
#endif

// Note: Functions marked optimistic constexpr can not portably be evaluated in a constant expression
#define DLA_OPTIMISTIC_CONSTEXPR constexpr
