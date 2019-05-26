#include <vector.h>
#include <matrix.h>
#include <units.h>
#include <to_string.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;

TEST_CASE("Test for string conversion of base unit types", "[to_string_base_unit]") {
	REQUIRE(to_string(length_unit{}) == "base_unit");
}

TEST_CASE("Test for string conversion of composite unit types", "[to_string_comp_unit]") {
	REQUIRE(to_string(velocity_unit{}) == "comp_unit");
}

TEST_CASE("Test for string conversion of vector types", "[to_string_vector]") {
	REQUIRE(to_string(vec1{}) == "vec");
}

TEST_CASE("Test for string conversion of matrix types", "[to_string_matrix]") {
	REQUIRE(to_string(tmat1<float>{}) == "mat");
}
