#include "common.h"

#include <dla/vector.h>
#include <dla/matrix.h>
#include <dla/to_string.h>

#include <catch2/catch_test_macros.hpp>

#include <type_traits>

auto test = [](auto... args) {
	using underlying_type = std::common_type_t<decltype(args)...>;
	using reference_vec = dla::vec<std::add_lvalue_reference_t<underlying_type>, sizeof...(args)>;
	using value_vec = dla::vec<underlying_type, sizeof...(args)>;
	auto reference_vector = reference_vec{ args... };
	auto expected_vector = value_vec{ args... };

	int test_result = 0;

	test_result += (reference_vector != expected_vector);

	((args += 6), ...);
	auto new_expected_vector = value_vec{ args... };
	test_result += (reference_vector != new_expected_vector);

	auto assignee_vector = value_vec{ (args / 2)... };
	reference_vector = assignee_vector;
	{
		int i = 0;
		(
			(
				test_result += (args != assignee_vector[i]),
				i++
			),
			...
		);
	}

	((args *= 3), ...);
		auto assigned_vector = value_vec{ reference_vector };
	{
		int i = 0;
		(
			(
				test_result += (args != assigned_vector[i]),
				i++
			),
			...
		);
	}

	((args *= 3), ...);
	auto decayed_vector = reference_vector.decay();
	{
		int i = 0;
		(
			(
				test_result += (args != decayed_vector[i]),
				i++
			),
			...
		);
	}

	return test_result;
};
DLA_TEST_CONSTEXPR auto test_result_vec1 = test(1);
DLA_TEST_CONSTEXPR auto test_result_vec2 = test(1, 8);
DLA_TEST_CONSTEXPR auto test_result_vec3 = test(-1, 5, 5);
DLA_TEST_CONSTEXPR auto test_result_vec4 = test(1, 2, 12, 188);

TEST_CASE("Test vector of references", "[vector_reference]") {
	REQUIRE(test_result_vec1 == 0);
	REQUIRE(test_result_vec2 == 0);
	REQUIRE(test_result_vec3 == 0);
	REQUIRE(test_result_vec4 == 0);
}
