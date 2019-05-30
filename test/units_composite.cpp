#include <units.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using namespace int_literals;
constexpr auto length = 1_m;
constexpr auto time_value = 1_s;
constexpr auto weight = 1_kg;
constexpr auto frequency = 1.0f / time_value;

constexpr auto volume = length * length * length;
constexpr auto velocity = length / time_value;
constexpr auto same_velocity = frequency * length;
constexpr auto acceleration = length / time_value / time_value;
constexpr auto same_acceleration = frequency * frequency * length;
constexpr auto force = acceleration * weight;
constexpr auto same_force = (frequency * length) * (weight / time_value);
constexpr auto dim_less = length / length;
constexpr auto other_dim_less = velocity / same_velocity;
constexpr auto more_dim_less = time_value * acceleration / length / frequency;
constexpr auto last_dim_less = acceleration / acceleration;

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
