#include "common.h"

#include <units.h>
#include <scalar_math.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using namespace int_literals;

constexpr auto length = 1_m;
constexpr auto time_value = 1_s;
constexpr auto weight = 1_kg;
constexpr auto force = length * weight / time_value / time_value;

constexpr auto three = 3.0f;
auto cbrt_three = math::cbrt(three);
auto three_again = cbrt_three * cbrt_three * cbrt_three;

auto length_sqrt = math::sqrt(length);
auto length_cbrt = math::cbrt(length);
auto length_full = math::pow<2>(length_sqrt);
auto force_sqrt = math::sqrt(force);
auto force_cbrt = math::cbrt(force);
auto force_full = math::pow<2>(force_sqrt);

TEST_CASE("Test math operations on units", "[units_math]") {
	REQUIRE(math::abs(three - three_again) < 0.000001f);
	REQUIRE(std::is_same_v<decltype(length_full), decltype(math::pow<3>(length_cbrt))>);
	REQUIRE(std::is_same_v<decltype(force_full), decltype(math::pow<3>(force_cbrt))>);
	REQUIRE(is_similar<length_unit>(length_full));
	REQUIRE(is_similar<force_unit>(force_full));
}
