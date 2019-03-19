#include <vector.h>
#include <matrix.h>

#include <type_traits>

int main() {
	using namespace dla;
	auto test = [](auto... args) {
		using type = std::common_type_t<decltype(args)...>;
		auto reference_vector = dla::vec<std::add_lvalue_reference_t<type>, sizeof...(args)>{ args... };
		auto expected_vector = dla::vec<type, sizeof...(args)>{ args... };

		int test_result = 0;

		test_result += (reference_vector != expected_vector);

		((args += 6), ...);
		auto new_expected_vector = dla::vec<type, sizeof...(args)>{ args... };
		test_result += (reference_vector != new_expected_vector);

		auto assignee_vector = dla::vec<type, sizeof...(args)>{ (args / 2)... };
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
		auto assigned_vector = reference_vector;
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
