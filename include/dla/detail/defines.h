#pragma once

#ifdef _MSVC_LANG
#   define declare_unreachable() __assume(false)
#else
#   define declare_unreachable() __builtin_unreachable()
#endif
