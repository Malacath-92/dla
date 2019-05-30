#include "common.h"

#include <vector.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
constexpr auto right = ivec3(0, 1, 0);
constexpr auto left = ivec3(0, -1, 0);
constexpr auto up_f = vec3(0.0f, 0.0f, 1.0f);
constexpr auto diag_f = vec3(1.0f, 1.0f, 1.0f);
constexpr auto other_diag_f = vec3(0.0f, 1.0f, 1.0f);

constexpr auto minus_one = right.dot(left);
constexpr auto zero = up_f.dot(left);
constexpr auto one = up_f.dot(diag_f);
constexpr auto other_minus_one = left.dot(diag_f);
constexpr auto two = other_diag_f.dot(diag_f);

TEST_CASE("Test vector dot products", "[vector_dot]") {
    REQUIRE(minus_one == -1);
    REQUIRE(zero == 0.0f);
    REQUIRE(one == 1.0f);
    REQUIRE(other_minus_one == -1.0f);
	REQUIRE(two == 2.0f);
}
