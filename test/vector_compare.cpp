#include <vector.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;

constexpr auto one_two_three = ivec3(1, 2, 3);
constexpr auto three_two_one = ivec3(3, 2, 1);
constexpr auto false_true_false = one_two_three.compare(three_two_one);

TEST_CASE("Test math operations on units", "[vector_compare]") {
	REQUIRE(false_true_false == bvec3(false, true, false));
}