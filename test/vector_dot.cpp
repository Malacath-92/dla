#include "common.h"

#include <dla/vector.h>
#include <dla/to_string.h>

#include <catch2/catch.hpp>

using namespace dla;
DLA_TEST_CONSTEXPR auto right = ivec3(0, 1, 0);
DLA_TEST_CONSTEXPR auto left = ivec3(0, -1, 0);
DLA_TEST_CONSTEXPR auto up_f = vec3(0.0f, 0.0f, 1.0f);
DLA_TEST_CONSTEXPR auto diag_f = vec3(1.0f, 1.0f, 1.0f);
DLA_TEST_CONSTEXPR auto other_diag_f = vec3(0.0f, 1.0f, 1.0f);

DLA_TEST_CONSTEXPR auto minus_one = right.dot(left);
DLA_TEST_CONSTEXPR auto zero = up_f.dot(left);
DLA_TEST_CONSTEXPR auto one = up_f.dot(diag_f);
DLA_TEST_CONSTEXPR auto other_minus_one = left.dot(diag_f);
DLA_TEST_CONSTEXPR auto two = other_diag_f.dot(diag_f);

TEST_CASE("Test vector dot products", "[vector_dot]") {
    REQUIRE(minus_one == -1);
    REQUIRE(zero == 0.0f);
    REQUIRE(one == 1.0f);
    REQUIRE(other_minus_one == -1.0f);
	REQUIRE(two == 2.0f);
}
