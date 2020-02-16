#include "common.h"

#include <units.h>
#include <scalar_math.h>
#include <literals.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using namespace literals;
using namespace int_literals;

DLA_TEST_CONSTEXPR auto length = 1_m;
DLA_TEST_CONSTEXPR auto time_value = 1_s;
DLA_TEST_CONSTEXPR auto weight = 1_kg;
DLA_TEST_CONSTEXPR auto force = length * weight / time_value / time_value;

DLA_TEST_CONSTEXPR auto weird_length = 1.232_m;
DLA_TEST_CONSTEXPR auto weird_time_value = -5.655_s;
DLA_TEST_CONSTEXPR auto weird_weight = -43.221_kg;
DLA_TEST_CONSTEXPR auto weird_force = 6.3245_N;

DLA_TEST_CONSTEXPR auto three = 3.0f;
auto cbrt_three = math::cbrt(three);
auto three_again = cbrt_three * cbrt_three * cbrt_three;

auto length_sqrt = math::sqrt(length);
auto length_cbrt = math::cbrt(length);
auto length_full = math::pow<2>(length_sqrt);
auto force_sqrt = math::sqrt(force);
auto force_cbrt = math::cbrt(force);
auto force_full = math::pow<2>(force_sqrt);

auto length_floor = math::floor(weird_length);
auto time_ceil = math::ceil(weird_time_value);
auto weight_round = math::round(weird_weight);
auto force_round = math::round(weird_force);

TEST_CASE("Test math operations on units", "[units_math]") {
	REQUIRE(math::abs(three - three_again) < 0.000001f);
	REQUIRE(std::is_same_v<decltype(length_full), decltype(math::pow<3>(length_cbrt))>);
	REQUIRE(std::is_same_v<decltype(force_full), decltype(math::pow<3>(force_cbrt))>);
	REQUIRE(is_similar<length_unit>(length_full));
	REQUIRE(is_similar<force_unit>(force_full));
	REQUIRE(math::abs(length_floor - 1_m) < 0.000001_m);
	REQUIRE(math::abs(time_ceil + 5_s) < 0.000001_s);
	REQUIRE(math::abs(weight_round + 43_kg) < 0.000001_kg);
	REQUIRE(math::abs(force_round - 6_N) < 0.000001_N);
}
