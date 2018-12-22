#include "units.h"

namespace unit::literals {
    constexpr auto operator ""_m(long double v) { return length_unit{ float(v) }; }
    constexpr auto operator ""_s(long double v) { return time_unit{ float(v) }; }
    constexpr auto operator ""_kg(long double v) { return weight_unit{ float(v) }; }
}