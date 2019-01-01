#include "units.h"
#include "scalar_math.h"
#include "literals.h"

int main() {
	using namespace dla;
	using namespace int_literals;
    constexpr auto length = 1_m;
    constexpr auto time = 1_s;
    constexpr auto weight = 1_kg;
	constexpr auto force = length * weight / time / time;

	auto length_sqrt = math::sqrt(length);
	auto length_cbrt = math::cbrt(length);
	auto length_full = math::pow<2>(length_sqrt);
	length_full = math::pow<3>(length_cbrt);
	auto force_sqrt = math::sqrt(force);
	auto force_cbrt = math::cbrt(force);
	auto force_full = math::pow<2>(force_sqrt);
	force_full = math::pow<3>(force_cbrt);
	static_assert(std::is_same_v<std::remove_const_t<decltype(length_full)>, length_unit>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(force_full)>, force_unit>);
}