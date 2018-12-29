#include "detail/tuple_sort.h"

template <class T, class U>
struct sort_by_sizeof_in_descending_order {
	static constexpr bool value = sizeof(T) < sizeof(U);
};
template <class T, class U>
struct sort_by_sizeof_in_ascending_order {
	static constexpr bool value = sizeof(T) > sizeof(U);
};

int main() {
	using namespace dla;
	using input_tuple_t = std::tuple<char, int, char, double, char, float>;
	using expected_descending_tuple_t = std::tuple<double, int, float, char, char, char>;
	using expected_ascending_tuple_t = std::tuple<char, char, char, int, float, double>;

	using result_descending_tuple_t = detail::tuple_selection_sort_t<sort_by_sizeof_in_descending_order, input_tuple_t>;
	using result_aescending_tuple_t = detail::tuple_selection_sort_t<sort_by_sizeof_in_ascending_order, input_tuple_t>;
	static_assert(std::is_same_v<expected_descending_tuple_t, result_descending_tuple_t>, "Failed sorting in descending order tuple!");
	static_assert(std::is_same_v<expected_ascending_tuple_t, result_aescending_tuple_t>, "Failed sorting in ascending order tuple!");
}