#include <vector.h>
#include <matrix.h>

#include <type_traits>

int main() {
	using namespace dla;
	auto test = []() {
		int a = 0;
		int b = 1;
		auto reference_vector = dla::tvec3<int&>{ a, a, b };
		auto expected_vector = dla::tvec3<int>{ a, a, b };

		int test_result = 0;

		test_result += (reference_vector != expected_vector);

		a = 5;
		b = 0;
		auto new_expected_vector = dla::tvec3<int>{ a, a, b };
		test_result += (reference_vector != new_expected_vector);

		return test_result;
	};
	auto test_result = test();

	int error = 0;

	error += test_result;

	return error;
}
