#include "common.h"

#include <units.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


using namespace dla;

using namespace literals;

DLA_TEST_CONSTEXPR auto length = 1.0_m;
DLA_TEST_CONSTEXPR auto time_value = 1.0_s;
DLA_TEST_CONSTEXPR auto weight = 1.0_kg;

DLA_TEST_CONSTEXPR auto area = 1.0_m2;
DLA_TEST_CONSTEXPR auto volume = 1.0_m3;
DLA_TEST_CONSTEXPR auto frequency = 1.0_Hz;

DLA_TEST_CONSTEXPR auto velocity = 1.0_m_s;
DLA_TEST_CONSTEXPR auto acceleration = 1.0_m_s2;
DLA_TEST_CONSTEXPR auto force = 1.0_N;
DLA_TEST_CONSTEXPR auto impulse = 1.0_Ns;
DLA_TEST_CONSTEXPR auto density = 1.0_rho;
DLA_TEST_CONSTEXPR auto energy = 1.0_J;
DLA_TEST_CONSTEXPR auto power = 1.0_W;
DLA_TEST_CONSTEXPR auto pressure = 1.0_Pa;

using namespace int_literals;

DLA_TEST_CONSTEXPR auto length_int = 1_m;
DLA_TEST_CONSTEXPR auto time_int = 1_s;
DLA_TEST_CONSTEXPR auto weight_int = 1_kg;

DLA_TEST_CONSTEXPR auto area_int = 1_m2;
DLA_TEST_CONSTEXPR auto volume_int = 1_m3;
DLA_TEST_CONSTEXPR auto frequency_int = 1_Hz;

DLA_TEST_CONSTEXPR auto velocity_int = 1_m_s;
DLA_TEST_CONSTEXPR auto acceleration_int = 1_m_s2;
DLA_TEST_CONSTEXPR auto force_int = 1_N;
DLA_TEST_CONSTEXPR auto impulse_int = 1_Ns;
DLA_TEST_CONSTEXPR auto density_int = 1_rho;
DLA_TEST_CONSTEXPR auto energy_int = 1_J;
DLA_TEST_CONSTEXPR auto power_int = 1_W;
DLA_TEST_CONSTEXPR auto pressure_int = 1_Pa;

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
