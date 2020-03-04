#include "common.h"

#include <vector.h>
#include <to_string.h>

#include <catch2/catch.hpp>

using namespace dla;

DLA_TEST_CONSTEXPR auto only_one_element = vec1(1.0f);
[[maybe_unused]] DLA_TEST_CONSTEXPR float just_that_element = only_one_element;

DLA_TEST_CONSTEXPR auto float_vec = vec3(1.0f);
DLA_TEST_CONSTEXPR auto double_vec = dvec3(1.0f);
DLA_TEST_CONSTEXPR auto int_vec = ivec3(1);
DLA_TEST_CONSTEXPR auto uint_vec = uvec3(1u);
DLA_TEST_CONSTEXPR auto fd_prod_vec = float_vec * double_vec;
DLA_TEST_CONSTEXPR auto id_prod_vec = int_vec * double_vec;
DLA_TEST_CONSTEXPR auto iu_prod_vec = int_vec * uint_vec;

TEST_CASE("Test conversion of types during vector operations", "[vector_conversion]") {
	REQUIRE(is_similar<dvec3>(fd_prod_vec));
	REQUIRE(is_similar<dvec3>(id_prod_vec));
	REQUIRE(is_similar<uvec3>(iu_prod_vec));
}
