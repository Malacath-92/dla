#include <units.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


using namespace dla;

using namespace literals;

constexpr auto length = 1.0_m;
constexpr auto time_value = 1.0_s;
constexpr auto weight = 1.0_kg;

constexpr auto area = 1.0_m2;
constexpr auto volume = 1.0_m3;
constexpr auto frequency = 1.0_Hz;

constexpr auto velocity = 1.0_m_s;
constexpr auto acceleration = 1.0_m_s2;
constexpr auto force = 1.0_N;
constexpr auto impulse = 1.0_Ns;
constexpr auto density = 1.0_rho;
constexpr auto energy = 1.0_J;
constexpr auto power = 1.0_W;
constexpr auto pressure = 1.0_Pa;

using namespace int_literals;

constexpr auto length_int = 1_m;
constexpr auto time_int = 1_s;
constexpr auto weight_int = 1_kg;

constexpr auto area_int = 1_m2;
constexpr auto volume_int = 1_m3;
constexpr auto frequency_int = 1_Hz;

constexpr auto velocity_int = 1_m_s;
constexpr auto acceleration_int = 1_m_s2;
constexpr auto force_int = 1_N;
constexpr auto impulse_int = 1_Ns;
constexpr auto density_int = 1_rho;
constexpr auto energy_int = 1_J;
constexpr auto power_int = 1_W;
constexpr auto pressure_int = 1_Pa;

TEST_CASE("Test that unit literals construct the right types", "[units_literals]") {
	REQUIRE(length == length_unit{ 1.0f });
	REQUIRE(time_value == time_unit{ 1.0f });
	REQUIRE(weight == weight_unit{ 1.0f });

	REQUIRE(area == area_unit{ 1.0f });
	REQUIRE(volume == volume_unit{ 1.0f });
	REQUIRE(frequency == frequency_unit{ 1.0f });

	REQUIRE(velocity == velocity_unit{ 1.0f });
	REQUIRE(acceleration == acceleration_unit{ 1.0f });
	REQUIRE(force == force_unit{ 1.0f });
	REQUIRE(impulse == impulse_unit{ 1.0f });
	REQUIRE(density == density_unit{ 1.0f });
	REQUIRE(energy == energy_unit{ 1.0f });
	REQUIRE(power == power_unit{ 1.0f });
	REQUIRE(pressure == pressure_unit{ 1.0f });
}

TEST_CASE("Test that unit literals construct the right types from integers", "[units_int_literals]") {
	REQUIRE(length_int == length_unit{ 1.0f });
	REQUIRE(time_int == time_unit{ 1.0f });
	REQUIRE(weight_int == weight_unit{ 1.0f });

	REQUIRE(area_int == area_unit{ 1.0f });
	REQUIRE(volume_int == volume_unit{ 1.0f });
	REQUIRE(frequency_int == frequency_unit{ 1.0f });

	REQUIRE(velocity_int == velocity_unit{ 1.0f });
	REQUIRE(acceleration_int == acceleration_unit{ 1.0f });
	REQUIRE(force_int == force_unit{ 1.0f });
	REQUIRE(impulse_int == impulse_unit{ 1.0f });
	REQUIRE(density_int == density_unit{ 1.0f });
	REQUIRE(energy_int == energy_unit{ 1.0f });
	REQUIRE(power_int == power_unit{ 1.0f });
	REQUIRE(pressure_int == pressure_unit{ 1.0f });
}
