#include "common.h"

#include "units.h"
#include "literals.h"

int main() {
	using namespace dla;

	{
		using namespace literals;

		constexpr auto length = 0.0_m;
		constexpr auto time = 0.0_s;
		constexpr auto weight = 0.0_kg;
		static_assert(is_similar<length_unit>(length));
		static_assert(is_similar<time_unit>(time));
		static_assert(is_similar<weight_unit>(weight));

		constexpr auto area = 0.0_m2;
		constexpr auto volume = 0.0_m3;
		constexpr auto frequency = 0.0_Hz;
		static_assert(is_similar<area_unit>(area));
		static_assert(is_similar<volume_unit>(volume));
		static_assert(is_similar<frequency_unit>(frequency));

		constexpr auto velocity = 0.0_m_s;
		constexpr auto acceleration = 0.0_m_s2;
		constexpr auto force = 0.0_N;
		constexpr auto impulse = 0.0_Ns;
		constexpr auto density = 0.0_rho;
		constexpr auto energy = 0.0_J;
		constexpr auto power = 0.0_W;
		constexpr auto pressure = 0.0_Pa;
		static_assert(is_similar<velocity_unit>(velocity));
		static_assert(is_similar<acceleration_unit>(acceleration));
		static_assert(is_similar<force_unit>(force));
		static_assert(is_similar<impulse_unit>(impulse));
		static_assert(is_similar<density_unit>(density));
		static_assert(is_similar<energy_unit>(energy));
		static_assert(is_similar<power_unit>(power));
		static_assert(is_similar<pressure_unit>(pressure));
	}

	{
		using namespace int_literals;

		constexpr auto length = 0_m;
		constexpr auto time = 0_s;
		constexpr auto weight = 0_kg;
		static_assert(is_similar<length_unit>(length));
		static_assert(is_similar<time_unit>(time));
		static_assert(is_similar<weight_unit>(weight));

		constexpr auto area = 0_m2;
		constexpr auto volume = 0_m3;
		constexpr auto frequency = 0_Hz;
		static_assert(is_similar<area_unit>(area));
		static_assert(is_similar<volume_unit>(volume));
		static_assert(is_similar<frequency_unit>(frequency));

		constexpr auto velocity = 0_m_s;
		constexpr auto acceleration = 0_m_s2;
		constexpr auto force = 0_N;
		constexpr auto impulse = 0_Ns;
		constexpr auto density = 0_rho;
		constexpr auto energy = 0_J;
		constexpr auto power = 0_W;
		constexpr auto pressure = 0_Pa;
		static_assert(is_similar<velocity_unit>(velocity));
		static_assert(is_similar<acceleration_unit>(acceleration));
		static_assert(is_similar<force_unit>(force));
		static_assert(is_similar<impulse_unit>(impulse));
		static_assert(is_similar<density_unit>(density));
		static_assert(is_similar<energy_unit>(energy));
		static_assert(is_similar<power_unit>(power));
		static_assert(is_similar<pressure_unit>(pressure));
	}
}
