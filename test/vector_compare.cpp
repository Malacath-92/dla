#include "common.h"

#include <dla/vector.h>
#include <dla/to_string.h>

#include <catch2/catch.hpp>

using namespace dla;

DLA_TEST_CONSTEXPR auto one_two_three = ivec3(1, 2, 3);
DLA_TEST_CONSTEXPR auto three_two_one = ivec3(3, 2, 1);
DLA_TEST_CONSTEXPR auto false_true_false = one_two_three.compare(three_two_one);

TEST_CASE("Test math operations on units", "[vector_compare]") {
	REQUIRE(false_true_false == bvec3(false, true, false));
}
