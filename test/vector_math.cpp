#include "common.h"

#include <dla/vector.h>
#include <dla/vector_math.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

using namespace dla;

DLA_TEST_CONSTEXPR auto vector = dla::vec4{ 1.4f, 1.6f, -1.6f, -1.4f };
DLA_TEST_CONSTEXPR auto other_vector = dla::vec4{ 0.0f, 2.0f, 0.0f, 2.0f };

auto abs_vec = dla::abs(vector);

auto floor_vec = dla::ivec4(dla::floor(vector));
auto ceil_vec = dla::ivec4(dla::ceil(vector));
auto round_vec = dla::ivec4(dla::round(vector));
auto min_vec = dla::ivec4(dla::min(vector, other_vector));
auto max_vec = dla::ivec4(dla::max(vector, other_vector));

TEST_CASE("Test math operations on vectors", "[vector_math]") {
	REQUIRE(abs_vec == dla::vec4{ 1.4f, 1.6f, 1.6f, 1.4f });
	REQUIRE(floor_vec == dla::ivec4{ 1, 1, -2, -2 });
	REQUIRE(ceil_vec == dla::ivec4{ 2, 2, -1, -1 });
	REQUIRE(round_vec == dla::ivec4{ 1, 2, -2, -1 });
	REQUIRE(min_vec == dla::ivec4{ 0, 1, -2, -1 });
	REQUIRE(max_vec == dla::ivec4{ 1, 2, 0, 2 });
}
