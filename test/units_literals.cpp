#include "units.h"
#include "literals.h"

int main() {
	using namespace dla;

	{
		using namespace literals;

		constexpr auto length = 0.0_m;
		constexpr auto time = 0.0_s;
		constexpr auto weight = 0.0_kg;
		static_assert(std::is_same_v<std::remove_const_t<decltype(length)>, length_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(time)>, time_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(weight)>, weight_unit>);

		constexpr auto area = 0.0_m2;
		constexpr auto volume = 0.0_m3;
		constexpr auto frequency = 0.0_Hz;
		static_assert(std::is_same_v<std::remove_const_t<decltype(area)>, area_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(volume)>, volume_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(frequency)>, frequency_unit>);

		constexpr auto velocity = 0.0_m_s;
		constexpr auto acceleration = 0.0_m_s2;
		constexpr auto force = 0.0_N;
		constexpr auto impulse = 0.0_Ns;
		constexpr auto density = 0.0_rho;
		constexpr auto energy = 0.0_J;
		constexpr auto power = 0.0_W;
		constexpr auto pressure = 0.0_Pa;
		static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, velocity_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, acceleration_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, force_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(impulse)>, impulse_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(density)>, density_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(energy)>, energy_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(power)>, power_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(pressure)>, pressure_unit>);
	}

	{
		using namespace int_literals;

		constexpr auto length = 0_m;
		constexpr auto time = 0_s;
		constexpr auto weight = 0_kg;
		static_assert(std::is_same_v<std::remove_const_t<decltype(length)>, length_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(time)>, time_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(weight)>, weight_unit>);

		constexpr auto area = 0_m2;
		constexpr auto volume = 0_m3;
		constexpr auto frequency = 0_Hz;
		static_assert(std::is_same_v<std::remove_const_t<decltype(area)>, area_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(volume)>, volume_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(frequency)>, frequency_unit>);

		constexpr auto velocity = 0_m_s;
		constexpr auto acceleration = 0_m_s2;
		constexpr auto force = 0_N;
		constexpr auto impulse = 0_Ns;
		constexpr auto density = 0_rho;
		constexpr auto energy = 0_J;
		constexpr auto power = 0_W;
		constexpr auto pressure = 0_Pa;
		static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, velocity_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, acceleration_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, force_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(impulse)>, impulse_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(density)>, density_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(energy)>, energy_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(power)>, power_unit>);
		static_assert(std::is_same_v<std::remove_const_t<decltype(pressure)>, pressure_unit>);
	}
}
