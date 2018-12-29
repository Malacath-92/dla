#pragma once

#include "units.h"

namespace unit::literals {
    constexpr auto operator ""_m(long double v) { return length_unit{ float(v) }; }
    constexpr auto operator ""_s(long double v) { return time_unit{ float(v) }; }
    constexpr auto operator ""_kg(long double v) { return weight_unit{ float(v) }; }

    constexpr auto operator ""_m2(long double v) { return area_unit{ float(v) }; }
    constexpr auto operator ""_m3(long double v) { return volume_unit{ float(v) }; }
    constexpr auto operator ""_Hz(long double v) { return frequency_unit{ float(v) }; }

    constexpr auto operator ""_m_s(long double v) { return velocity_unit{ float(v) }; }
    constexpr auto operator ""_m_s2(long double v) { return acceleration_unit{ float(v) }; }
    constexpr auto operator ""_N(long double v) { return force_unit{ float(v) }; }
    constexpr auto operator ""_Ns(long double v) { return impulse_unit{ float(v) }; }
    constexpr auto operator ""_rho(long double v) { return density_unit{ float(v) }; }
    constexpr auto operator ""_J(long double v) { return energy_unit{ float(v) }; }
    constexpr auto operator ""_W(long double v) { return power_unit{ float(v) }; }
    constexpr auto operator ""_Pa(long double v) { return pressure_unit{ float(v) }; }
}
namespace unit::int_literals {
    constexpr auto operator ""_m(unsigned long long v) { return length_unit{ float(v) }; }
    constexpr auto operator ""_s(unsigned long long v) { return time_unit{ float(v) }; }
    constexpr auto operator ""_kg(unsigned long long v) { return weight_unit{ float(v) }; }

    constexpr auto operator ""_m2(unsigned long long v) { return area_unit{ float(v) }; }
    constexpr auto operator ""_m3(unsigned long long v) { return volume_unit{ float(v) }; }
    constexpr auto operator ""_Hz(unsigned long long v) { return frequency_unit{ float(v) }; }

    constexpr auto operator ""_m_s(unsigned long long v) { return velocity_unit{ float(v) }; }
    constexpr auto operator ""_m_s2(unsigned long long v) { return acceleration_unit{ float(v) }; }
    constexpr auto operator ""_N(unsigned long long v) { return force_unit{ float(v) }; }
    constexpr auto operator ""_Ns(unsigned long long v) { return impulse_unit{ float(v) }; }
    constexpr auto operator ""_rho(unsigned long long v) { return density_unit{ float(v) }; }
    constexpr auto operator ""_J(unsigned long long v) { return energy_unit{ float(v) }; }
    constexpr auto operator ""_W(unsigned long long v) { return power_unit{ float(v) }; }
    constexpr auto operator ""_Pa(unsigned long long v) { return pressure_unit{ float(v) }; }
}