#include "units.h"
#include "literals.h"
#include "vector.h"

#include <type_traits>

int main() {
	using namespace dla;
	using namespace literals;
	using namespace int_literals;
	using manhattan = dla::distances::manhattan<dla::length_unit>;
	constexpr auto right = vec(0_m, 1_m, 0_m);
	constexpr auto left = vec(0_m, -1_m, 0_m);
	constexpr auto up = vec(0_m, 0_m, 1_m);
	constexpr auto diag = vec(1_m, 1_m, 1_m);

	auto almost_same = [](auto&& lhs, auto&& rhs) {
		using T = std::remove_reference_t<decltype(lhs)>;
		return math::abs(lhs - rhs) <= T{ 0.000001f };
	};

	int error = 0;
	
	auto one_meter = right.length();
	auto one_other_meter = left.length();
	auto two_meter = left.distance(right);
	error += !almost_same(one_meter, 1_m);
	error += !almost_same(one_other_meter, 1_m);
	error += !almost_same(two_meter, 2_m);
	
	auto two_other_meter = right.distance(up, manhattan{});
	auto three_meter = diag.length(manhattan{});
	error += !almost_same(two_other_meter, 2_m);
	error += !almost_same(three_meter, 3_m);

	return error;
}