#include "units.h"
#include "literals.h"
#include "vector.h"

int main() {
	using namespace dla;
	using namespace literals;
	using namespace int_literals;
	constexpr auto scalar_gravity = -9.81_m_s2;

	constexpr auto vector_gravity = vec(0_m_s2, 0_m_s2, scalar_gravity);
	constexpr auto double_gravity = vector_gravity + vector_gravity;
	constexpr auto square_gravity = vector_gravity * vector_gravity;
	constexpr auto no_gravity = vector_gravity / vector_gravity.z;
	static_assert(std::is_same_v<std::remove_const_t<decltype(vector_gravity)>, vec<acceleration_unit, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(double_gravity)>, vec<acceleration_unit, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(square_gravity)>, vec<detail::power_t<acceleration_unit, 2, 1>, 3>>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(no_gravity)>, vec<float, 3>>);
}