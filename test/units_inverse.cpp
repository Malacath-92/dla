#include "common.h"

#include <units.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using namespace int_literals;
using inverse_time_t = frequency_unit;
using inverse_velocity_t = detail::sorted_comp_unit_t<time_unit, base_unit<tag::length, -1, 1>>;
using inverse_force_t = detail::sorted_comp_unit_t<base_unit<tag::time, 2, 1>, base_unit<tag::length, -1, 1>, base_unit<tag::weight, -1, 1>>;
DLA_TEST_CONSTEXPR auto time_value = 1_s;
DLA_TEST_CONSTEXPR auto velocity = 1_m_s;
DLA_TEST_CONSTEXPR auto force = 1_N;

DLA_TEST_CONSTEXPR auto inverse_time = 1.0f / time_value;
DLA_TEST_CONSTEXPR auto inverse_velocity = 1.0f / velocity;
DLA_TEST_CONSTEXPR auto inverse_force = 1.0f / force;

TEST_CASE("Test that types resulting from inveresion are correct", "[units_inverse]") {
	REQUIRE(inverse_time == inverse_time_t{ 1.0f });
	REQUIRE(inverse_velocity == inverse_velocity_t{ 1.0f });
	REQUIRE(inverse_force == inverse_force_t{ 1.0f });
}
