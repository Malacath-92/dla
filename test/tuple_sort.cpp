#include "common.h"

#include <dla/detail/tuple_sort.h>

#include <catch2/catch_test_macros.hpp>

template <class T, class U>
struct sort_by_sizeof_in_descending_order {
	static constexpr bool value = sizeof(T) < sizeof(U);
};
template <class T, class U>
struct sort_by_sizeof_in_ascending_order {
	static constexpr bool value = sizeof(T) > sizeof(U);
};

using namespace dla::detail;
using input_tuple_t = std::tuple<char, int, char, double, char, float>;
using expected_descending_tuple_t = std::tuple<double, int, float, char, char, char>;
using expected_ascending_tuple_t = std::tuple<char, char, char, int, float, double>;

using result_descending_tuple_t = tuple_selection_sort_t<sort_by_sizeof_in_descending_order, input_tuple_t>;
using result_aescending_tuple_t = tuple_selection_sort_t<sort_by_sizeof_in_ascending_order, input_tuple_t>;

TEST_CASE("Sort tuple by different predicates", "[tuple_sort]") {
	REQUIRE(std::is_same_v<expected_descending_tuple_t, result_descending_tuple_t>);
	REQUIRE(std::is_same_v<expected_ascending_tuple_t, result_aescending_tuple_t>);
}
