#include "common.h"

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

	static_assert(is_similar<volume_unit>(volume));
	static_assert(is_similar<velocity_unit>(velocity));
	static_assert(is_similar<velocity_unit>(same_velocity));
	static_assert(is_similar<acceleration_unit>(acceleration));
	static_assert(is_similar<acceleration_unit>(same_acceleration));
	static_assert(is_similar<force_unit>(force));
	static_assert(is_similar<force_unit>(same_force));
	static_assert(is_similar<float>(dim_less));
	static_assert(is_similar<float>(other_dim_less));
	static_assert(is_similar<float>(more_dim_less));
	static_assert(is_similar<float>(last_dim_less));
}