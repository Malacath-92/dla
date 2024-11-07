#include "common.h"

#include <dla/matrix.h>
#include <dla/matrix_math.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

namespace dla {
	using mat2 = tmat2<float>;
	using imat2 = tmat2<int>;
}
using namespace dla;


DLA_TEST_CONSTEXPR auto matrix = dla::mat2{ { 1.4f, 1.6f }, { -1.6f, -1.4f } };

auto abs_mat = dla::abs(matrix);

auto floor_mat = dla::imat2(dla::floor(matrix));
auto ceil_mat = dla::imat2(dla::ceil(matrix));
auto round_mat = dla::imat2(dla::round(matrix));

TEST_CASE("Test math operations on matrices", "[matrix_math]") {
	REQUIRE(abs_mat == dla::mat2{ { 1.4f, 1.6f }, { 1.6f, 1.4f } });
	REQUIRE(floor_mat == dla::imat2{ { 1, 1 }, { -2, -2 } });
	REQUIRE(ceil_mat == dla::imat2{ { 2, 2 }, { -1, -1 } });
	REQUIRE(round_mat == dla::imat2{ { 1, 2 }, { -2, -1 } });
}
