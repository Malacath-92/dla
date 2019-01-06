#include "common.h"

#include "units.h"
#include "literals.h"

int main() {
	using namespace dla;
	using namespace int_literals;
	using inverse_time_t = frequency_unit;
	using inverse_velocity_t = detail::sorted_comp_unit_t<time_unit, base_unit<tag::length, -1, 1>>;
	using inverse_force_t = detail::sorted_comp_unit_t<base_unit<tag::time, 2, 1>, base_unit<tag::length, -1, 1>, base_unit<tag::weight, -1, 1>>;
	constexpr auto time = 1_s;
	constexpr auto velocity = 1_m_s;
	constexpr auto force = 1_N;

	int error = 0;
	
	constexpr auto inverse_time = 1.0f / time;
	constexpr auto inverse_velocity = 1.0f / velocity;
	constexpr auto inverse_force = 1.0f / force;
	error += !is_similar<inverse_time_t>(inverse_time);
	error += !is_similar<inverse_velocity_t>(inverse_velocity);
	error += !is_similar<inverse_force_t>(inverse_force);

	return error;
}