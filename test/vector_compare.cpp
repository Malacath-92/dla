#include "vector.h"

int main() {
	using namespace dla;

	int error = 0;

	constexpr auto one_two_three = ivec3(1, 2, 3);
	constexpr auto three_two_one = ivec3(3, 2, 1);
	constexpr auto false_true_false = one_two_three.compare(three_two_one);
	error += false_true_false != bvec3(false, true, false);

	return error;
}