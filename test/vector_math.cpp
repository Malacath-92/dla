#include "common.h"

#include <dla/vector.h>
#include <dla/vector_math.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

using namespace dla;

DLA_TEST_CONSTEXPR auto vector = dla::vec4{ 1.4f, 1.6f, -1.6f, -1.4f };

auto abs_vec = dla::abs(vector);

auto floor_vec = dla::ivec4(dla::floor(vector));
auto ceil_vec = dla::ivec4(dla::ceil(vector));
auto round_vec = dla::ivec4(dla::round(vector));

TEST_CASE("Test math operations on vectors", "[vector_math]") {
	REQUIRE(abs_vec == dla::vec4{ 1.4f, 1.6f, 1.6f, 1.4f });
	REQUIRE(floor_vec == dla::ivec4{ 1, 1, -2, -2 });
	REQUIRE(ceil_vec == dla::ivec4{ 2, 2, -1, -1 });
	REQUIRE(round_vec == dla::ivec4{ 1, 2, -2, -1 });
}
