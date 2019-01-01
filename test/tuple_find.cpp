#include "detail/tuple_index.h"

int main() {
	using input_tuple_t = std::tuple<char, int, char, double, char, float>;

	constexpr std::size_t double_idx = dla::detail::tuple_find_v<double, input_tuple_t>;
	constexpr std::size_t char_idx = dla::detail::tuple_find_v<char, input_tuple_t>;
	constexpr std::size_t float_idx = dla::detail::tuple_find_v<float, input_tuple_t>;
	constexpr std::size_t char_star_idx = dla::detail::tuple_find_v<char*, input_tuple_t>;
	static_assert(double_idx == 3);
	static_assert(char_idx == 0);
	static_assert(float_idx == 5);
	static_assert(char_star_idx == dla::detail::tuple_index_npos);
}