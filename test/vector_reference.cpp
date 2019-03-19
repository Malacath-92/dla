#include <vector.h>
#include <matrix.h>

#include <type_traits>

int main() {
	using namespace dla;
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
	constexpr auto test_result_vec1 = test(1);
	constexpr auto test_result_vec2 = test(1, 8);
	constexpr auto test_result_vec3 = test(-1, 5, 5);
	constexpr auto test_result_vec4 = test(1, 2, 12, 188);

	int error = 0;

	error += test_result_vec1;
	error += test_result_vec2;
	error += test_result_vec3;
	error += test_result_vec4;

	return error;
}
