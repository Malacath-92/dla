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
		auto abs = [](auto&& val) {
			using T = std::remove_reference_t<decltype(val)>;
			return val > T{ 0.0f } ? val : -val;
		};
		using T = std::remove_reference_t<decltype(lhs)>;
		return abs(lhs - rhs) <= T{ 0.0001f };
	};
	
	constexpr auto one_meter = right.length();
	constexpr auto one_other_meter = left.length();
	constexpr auto two_meter = left.distance(right);
	static_assert(almost_same(one_meter, 1_m));
	static_assert(almost_same(one_other_meter, 1_m));
	static_assert(almost_same(two_meter, 2_m));
	
	constexpr auto two_other_meter = right.distance(up, manhattan{});
	constexpr auto three_meter = diag.length(manhattan{});
	static_assert(almost_same(two_other_meter, 2_m));
	static_assert(almost_same(three_meter, 3_m));
}