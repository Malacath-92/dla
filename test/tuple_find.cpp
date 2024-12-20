#include "common.h"

#include <dla/detail/tuple_find.h>

#include <catch2/catch_test_macros.hpp>

using namespace dla::detail;
using input_tuple_t = std::tuple<char, int, char, double, char, float>;

DLA_TEST_CONSTEXPR std::size_t double_idx = tuple_find_v<double, input_tuple_t>;
DLA_TEST_CONSTEXPR std::size_t char_idx = tuple_find_v<char, input_tuple_t>;
DLA_TEST_CONSTEXPR std::size_t float_idx = tuple_find_v<float, input_tuple_t>;
DLA_TEST_CONSTEXPR std::size_t char_star_idx = tuple_find_v<char*, input_tuple_t>;

TEST_CASE("Find elements in a tuple", "[tuple_find]") {
	REQUIRE(double_idx == 3);
	REQUIRE(char_idx == 0);
	REQUIRE(float_idx == 5);
	REQUIRE(char_star_idx == tuple_find_npos);
}
