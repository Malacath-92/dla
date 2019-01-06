#include "detail/tuple_find.h"

int main() {
	using input_tuple_t = std::tuple<char, int, char, double, char, float>;

	int error = 0;

	constexpr std::size_t double_idx = dla::detail::tuple_find_v<double, input_tuple_t>;
	constexpr std::size_t char_idx = dla::detail::tuple_find_v<char, input_tuple_t>;
	constexpr std::size_t float_idx = dla::detail::tuple_find_v<float, input_tuple_t>;
	constexpr std::size_t char_star_idx = dla::detail::tuple_find_v<char*, input_tuple_t>;
	error += double_idx != 3;
	error += char_idx != 0;
	error += float_idx != 5;
	error += char_star_idx != dla::detail::tuple_find_npos;

	return error;
}