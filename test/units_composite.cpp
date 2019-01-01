#include "units.h"
#include "literals.h"

int main() {
	using namespace dla;
	using namespace int_literals;
    constexpr auto length = 1_m;
    constexpr auto time = 1_s;
    constexpr auto weight = 1_kg;
	constexpr auto frequency = 1.0f / time;

    constexpr auto volume = length * length * length;
	constexpr auto velocity = length / time;
	constexpr auto same_velocity = frequency * length;
	constexpr auto acceleration = length / time / time;
	constexpr auto same_acceleration = frequency * frequency * length;
	constexpr auto force = acceleration * weight;
	constexpr auto same_force = (frequency * length) * (weight / time);
	constexpr auto dim_less = length / length;
	constexpr auto other_dim_less = velocity / same_velocity;
	constexpr auto more_dim_less = time * acceleration / length / frequency;
	constexpr auto last_dim_less = acceleration / acceleration;

	static_assert(std::is_same_v<std::remove_const_t<decltype(volume)>, volume_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, velocity_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(velocity)>, std::remove_const_t<decltype(same_velocity)>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, acceleration_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(acceleration)>, std::remove_const_t<decltype(same_acceleration)>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, force_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(force)>, std::remove_const_t<decltype(same_force)>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(other_dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(more_dim_less)>, float>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(last_dim_less)>, float>);
}