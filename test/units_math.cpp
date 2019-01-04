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

	int error = 0;

	constexpr auto three = 3.0f;
	auto cbrt_three = math::cbrt(three);
	auto three_again = cbrt_three * cbrt_three * cbrt_three;
	error += !(math::abs(three - three_again) < 0.000001f);

	auto length_sqrt = math::sqrt(length);
	auto length_cbrt = math::cbrt(length);
	auto length_full = math::pow<2>(length_sqrt);
	length_full = math::pow<3>(length_cbrt);
	auto force_sqrt = math::sqrt(force);
	auto force_cbrt = math::cbrt(force);
	auto force_full = math::pow<2>(force_sqrt);
	force_full = math::pow<3>(force_cbrt);
	error += !std::is_same_v<std::remove_const_t<decltype(length_full)>, length_unit>;
	error += !std::is_same_v<std::remove_const_t<decltype(force_full)>, force_unit>;
}