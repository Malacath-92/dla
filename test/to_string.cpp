#include "common.h"

#include <dla/vector.h>
#include <dla/matrix.h>
#include <dla/units.h>
#include <dla/scalar_math.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

using namespace dla;

TEST_CASE("Test for string conversion of base unit types", "[to_string_base_unit]") {
	REQUIRE(to_string(math::sqrt(length_unit{ 5.0f })) == std::to_string(sqrt(5.0f)) + " m^(1/2)");
	REQUIRE(to_string(length_unit{ 5.0f }) == std::to_string(5.0f) + " m");
	REQUIRE(to_string(time_unit{ 5.0f }) == std::to_string(5.0f) + " s");
	REQUIRE(to_string(frequency_unit{ 5.0f }) == std::to_string(5.0f) + " s^-1");
	REQUIRE(to_string(weight_unit{ 5.0f }) == std::to_string(5.0f) + " kg");
}

TEST_CASE("Test for string conversion of composite unit types", "[to_string_comp_unit]") {
	REQUIRE(to_string(area_unit{ 5.0f }) == std::to_string(5.0f) + " m^2");
	REQUIRE(to_string(volume_unit{ 5.0f }) == std::to_string(5.0f) + " m^3");
	REQUIRE(to_string(velocity_unit{ 5.0f }) == std::to_string(5.0f) + " m s^-1");
	REQUIRE(to_string(force_unit{ 5.0f }) == std::to_string(5.0f) + " kg m s^-2");
}

TEST_CASE("Test for string conversion of vector types", "[to_string_vector]") {
	REQUIRE(to_string(ivec1{ 1 }) == "1");
	REQUIRE(to_string(ivec2{ 1, 2 }) == "{ 1, 2 }");
	REQUIRE(to_string(ivec3{ 1, 2, 3 }) == "{ 1, 2, 3 }");
	REQUIRE(to_string(ivec4{ 1, 2, 3, 4 }) == "{ 1, 2, 3, 4 }");
}

TEST_CASE("Test for string conversion of matrix types", "[to_string_matrix]") {
	REQUIRE(to_string(tmat1<int>{ 1 }) == "1");
	REQUIRE(to_string(tmat2<int>{ { 1, 2 }, { 3, 4 } }) == "{ { 1, 2 }, { 3, 4 } }");
	REQUIRE(to_string(tmat3<int>{ { 1, 2, 5 }, { 3, 4, 6 }, { 7, 8, 9 } }) == "{ { 1, 2, 5 }, { 3, 4, 6 }, { 7, 8, 9 } }");
}
