#include "common.h"

#include <units.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using namespace int_literals;
DLA_TEST_CONSTEXPR auto length = 1_m;
DLA_TEST_CONSTEXPR auto time_value = 1_s;
DLA_TEST_CONSTEXPR auto weight = 1_kg;
DLA_TEST_CONSTEXPR auto frequency = 1.0f / time_value;

DLA_TEST_CONSTEXPR auto volume = length * length * length;
DLA_TEST_CONSTEXPR auto velocity = length / time_value;
DLA_TEST_CONSTEXPR auto same_velocity = frequency * length;
DLA_TEST_CONSTEXPR auto acceleration = length / time_value / time_value;
DLA_TEST_CONSTEXPR auto same_acceleration = frequency * frequency * length;
DLA_TEST_CONSTEXPR auto force = acceleration * weight;
DLA_TEST_CONSTEXPR auto same_force = (frequency * length) * (weight / time_value);
DLA_TEST_CONSTEXPR auto dim_less = length / length;
DLA_TEST_CONSTEXPR auto other_dim_less = velocity / same_velocity;
DLA_TEST_CONSTEXPR auto more_dim_less = time_value * acceleration / length / frequency;
DLA_TEST_CONSTEXPR auto last_dim_less = acceleration / acceleration;

TEST_CASE("Test that types resulting from multiplicative operations are correct", "[units_composite]") {
	REQUIRE(volume == volume_unit{ 1.0f });
	REQUIRE(velocity == velocity_unit{ 1.0f });
	REQUIRE(same_velocity == velocity_unit{ 1.0f });
	REQUIRE(acceleration == acceleration_unit{ 1.0f });
	REQUIRE(same_acceleration == acceleration_unit{ 1.0f });
	REQUIRE(force == force_unit{ 1.0f });
	REQUIRE(same_force == force_unit{ 1.0f });
	REQUIRE(dim_less == float{ 1.0f });
	REQUIRE(other_dim_less == float{ 1.0f });
	REQUIRE(more_dim_less == float{ 1.0f });
	REQUIRE(last_dim_less == float{ 1.0f });
}
