#include "common.h"

#include "units.h"
#include "literals.h"

int main() {
	using namespace dla;

	int error = 0;

	{
		using namespace literals;

		constexpr auto length = 0.0_m;
		constexpr auto time = 0.0_s;
		constexpr auto weight = 0.0_kg;
		error += !is_similar<length_unit>(length);
		error += !is_similar<time_unit>(time);
		error += !is_similar<weight_unit>(weight);

		constexpr auto area = 0.0_m2;
		constexpr auto volume = 0.0_m3;
		constexpr auto frequency = 0.0_Hz;
		error += !is_similar<area_unit>(area);
		error += !is_similar<volume_unit>(volume);
		error += !is_similar<frequency_unit>(frequency);

		constexpr auto velocity = 0.0_m_s;
		constexpr auto acceleration = 0.0_m_s2;
		constexpr auto force = 0.0_N;
		constexpr auto impulse = 0.0_Ns;
		constexpr auto density = 0.0_rho;
		constexpr auto energy = 0.0_J;
		constexpr auto power = 0.0_W;
		constexpr auto pressure = 0.0_Pa;
		error += !is_similar<velocity_unit>(velocity);
		error += !is_similar<acceleration_unit>(acceleration);
		error += !is_similar<force_unit>(force);
		error += !is_similar<impulse_unit>(impulse);
		error += !is_similar<density_unit>(density);
		error += !is_similar<energy_unit>(energy);
		error += !is_similar<power_unit>(power);
		error += !is_similar<pressure_unit>(pressure);
	}

	{
		using namespace int_literals;

		constexpr auto length = 0_m;
		constexpr auto time = 0_s;
		constexpr auto weight = 0_kg;
		error += !is_similar<length_unit>(length);
		error += !is_similar<time_unit>(time);
		error += !is_similar<weight_unit>(weight);

		constexpr auto area = 0_m2;
		constexpr auto volume = 0_m3;
		constexpr auto frequency = 0_Hz;
		error += !is_similar<area_unit>(area);
		error += !is_similar<volume_unit>(volume);
		error += !is_similar<frequency_unit>(frequency);

		constexpr auto velocity = 0_m_s;
		constexpr auto acceleration = 0_m_s2;
		constexpr auto force = 0_N;
		constexpr auto impulse = 0_Ns;
		constexpr auto density = 0_rho;
		constexpr auto energy = 0_J;
		constexpr auto power = 0_W;
		constexpr auto pressure = 0_Pa;
		error += !is_similar<velocity_unit>(velocity);
		error += !is_similar<acceleration_unit>(acceleration);
		error += !is_similar<force_unit>(force);
		error += !is_similar<impulse_unit>(impulse);
		error += !is_similar<density_unit>(density);
		error += !is_similar<energy_unit>(energy);
		error += !is_similar<power_unit>(power);
		error += !is_similar<pressure_unit>(pressure);
	}

	return error;
}
