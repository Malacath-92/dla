#include "units.h"
#include "scalar_math.h"
#include "literals.h"
#include "vector.h"

#include <iostream>

#include "tuple_sort.h"

template <class T, class U>
struct descending {
	static constexpr bool value = sizeof(U) > sizeof(T);
};

int main() {
	using namespace unit;
	using namespace literals;
	using namespace int_literals;

	using input_tuple_t = std::tuple<char, int, char, double, char, float>;
	using expected_tuple_t = std::tuple<double, int, float, char, char, char>;
	using result_tuple_t = detail::tuple_selection_sort_t<descending, input_tuple_t>;
	static_assert(std::is_same_v<expected_tuple_t, result_tuple_t>, "Failed sorting tuple!");

	constexpr std::size_t double_idx = detail::tuple_find_v<double, input_tuple_t>;
	constexpr std::size_t char_idx = detail::tuple_find_v<char, input_tuple_t>;
	constexpr std::size_t float_idx = detail::tuple_find_v<float, input_tuple_t>;
	constexpr std::size_t char_star_idx = detail::tuple_find_v<char*, input_tuple_t>;
	static_assert(double_idx == 3, "Failed finding type in tuple!");
	static_assert(char_idx == 0, "Failed finding type in tuple!");
	static_assert(float_idx == 5, "Failed finding type in tuple!");
	static_assert(char_star_idx == detail::tuple_index_npos, "Found non-existant type in tuple!");

    constexpr auto length = 1.0_m;
    constexpr auto time = 1.0_s;
    constexpr auto weight = 1.0_kg;
	static_assert(std::is_same_v<std::remove_const_t<decltype(length)>, length_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(time)>, time_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(weight)>, weight_unit>);

	constexpr auto frequency = 1.0f / time;
	static_assert(std::is_same_v<std::remove_const_t<decltype(frequency)>, frequency_unit>);

    constexpr auto volume = length * length * length;
	static_assert(std::is_same_v<std::remove_const_t<decltype(volume)>, volume_unit>);

	constexpr auto velocity = length / time;
	constexpr auto same_velocity = frequency * length;
	static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, velocity_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, std::remove_const_t<decltype(same_velocity)>>);

	constexpr auto acceleration = length / time / time;
	constexpr auto same_acceleration = frequency * frequency * length;
	static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, acceleration_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, std::remove_const_t<decltype(same_acceleration)>>);

	constexpr auto force = acceleration * weight;
	constexpr auto same_force = (frequency * length) * (weight / time);
	static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, force_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, std::remove_const_t<decltype(same_force)>>);

	constexpr auto dim_less = length / length;
	constexpr auto other_dim_less = velocity / same_velocity;
	constexpr auto more_dim_less = time * acceleration / length / frequency;
	constexpr auto last_dim_less = acceleration / acceleration;
	static_assert(std::is_same_v<std::remove_const_t<decltype(dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(other_dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(more_dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(last_dim_less)>, float>);

	auto length_sqrt = math::sqrt(length);
	auto length_cbrt = math::cbrt(length);
	auto length_full = math::pow<2>(length_sqrt);
	length_full = math::pow<3>(length_cbrt);
	static_assert(std::is_same_v<std::remove_const_t<decltype(length_full)>, length_unit>);

	using vector::vec;

	constexpr auto gravity = vec(0_m_s2, 0_m_s2, -9.81_m_s2);
	constexpr auto double_gravity = gravity + gravity;
	constexpr auto square_gravity = gravity * gravity;
	constexpr auto no_gravity = gravity / gravity.z;
	static_assert(std::is_same_v<std::remove_const_t<decltype(gravity)>, vec<acceleration_unit, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(double_gravity)>, vec<acceleration_unit, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(square_gravity)>, vec<detail::power_t<acceleration_unit, 2, 1>, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(no_gravity)>, vec<float, 3>>);

	constexpr auto dim_less_vec_double = vec(1.0, 1.0, 1.0);
	[[maybe_unused]] constexpr auto dim_less_vec_float = vec<float, 3>(dim_less_vec_double);
}