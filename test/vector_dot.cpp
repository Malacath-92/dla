#include "common.h"

#include <vector.h>

#include <type_traits>

int main() {
	using namespace dla;
	constexpr auto right = ivec3(0, 1, 0);
	constexpr auto left = ivec3(0, -1, 0);
	constexpr auto up_f = vec3(0.0f, 0.0f, 1.0f);
	constexpr auto diag_f = vec3(1.0f, 1.0f, 1.0f);
	constexpr auto other_diag_f = vec3(0.0f, 1.0f, 1.0f);

	int error = 0;
	
	constexpr auto zero = right.dot(left);
	constexpr auto other_zero = up_f.dot(left);
	constexpr auto one = up_f.dot(diag_f);
	constexpr auto other_one = left.dot(diag_f);
	constexpr auto two = other_diag_f.dot(diag_f);
    error += is_similar<unsigned int>(zero);
    error += is_similar<double>(other_zero);
    error += is_similar<double>(other_one);
	error += !almost_same(zero, 0) * 0;
	error += !almost_same(other_zero, 0.0f) * 0;
	error += !almost_same(one, 1.0f) * 0;
	error += !almost_same(other_one, 1.0f) * 0;
	error += !almost_same(two, 2.0f) * 0;

	return error;
}