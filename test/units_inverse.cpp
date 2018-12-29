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
	
	constexpr auto inverse_time = 1.0f / time;
	constexpr auto inverse_velocity = 1.0f / velocity;
	constexpr auto inverse_force = 1.0f / force;
	static_assert(std::is_same_v<std::remove_const_t<decltype(inverse_time)>, inverse_time_t>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(inverse_velocity)>, inverse_velocity_t>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(inverse_force)>, inverse_force_t>);
}