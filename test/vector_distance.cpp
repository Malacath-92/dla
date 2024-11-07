#include "common.h"

#include <dla/units.h>
#include <dla/literals.h>
#include <dla/vector.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

using namespace dla;
using namespace literals;
using namespace int_literals;
using manhattan = dla::distances::manhattan<dla::length_unit>;
DLA_TEST_CONSTEXPR auto right = vec(0_m, 1_m, 0_m);
DLA_TEST_CONSTEXPR auto left = vec(0_m, -1_m, 0_m);
DLA_TEST_CONSTEXPR auto up = vec(0_m, 0_m, 1_m);
DLA_TEST_CONSTEXPR auto diag = vec(1_m, 1_m, 1_m);

auto one_meter = right.length();
auto one_other_meter = left.length();
auto two_meter = left.distance(right);

auto two_other_meter = right.distance(up, manhattan{});

auto three_meter = diag.length(manhattan{});

TEST_CASE("Test distance arithmetics on vectors", "[vector_distance]") {
	REQUIRE(almost_same(one_meter, 1_m));
	REQUIRE(almost_same(one_other_meter, 1_m));
	REQUIRE(almost_same(two_meter, 2_m));
	REQUIRE(almost_same(two_other_meter, 2_m));
	REQUIRE(almost_same(three_meter, 3_m));
}
