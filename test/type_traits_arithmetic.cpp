#include "common.h"

#include <vector.h>
#include <matrix.h>
#include <type_traits.h>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;

TEST_CASE("Test for plus overloads of arithmetic types", "[type_traits_plus_arithmetic]") {
	REQUIRE(overloads_plus_v<short, int>);
	REQUIRE(overloads_plus_v<int, int>);
	REQUIRE(overloads_plus_v<float, int>);
	REQUIRE(overloads_plus_v<int, short>);
	REQUIRE(overloads_plus_v<int, float>);

	REQUIRE(overloads_plus_v<short, double>);
	REQUIRE(overloads_plus_v<double, double>);
	REQUIRE(overloads_plus_v<float, double>);
	REQUIRE(overloads_plus_v<double, short>);
	REQUIRE(overloads_plus_v<double, float>);
}

TEST_CASE("Test for minus overloads of arithmetic types", "[type_traits_minus_arithmetic]") {
	REQUIRE(overloads_minus_v<short, int>);
	REQUIRE(overloads_minus_v<int, int>);
	REQUIRE(overloads_minus_v<float, int>);
	REQUIRE(overloads_minus_v<int, short>);
	REQUIRE(overloads_minus_v<int, float>);

	REQUIRE(overloads_minus_v<short, double>);
	REQUIRE(overloads_minus_v<double, double>);
	REQUIRE(overloads_minus_v<float, double>);
	REQUIRE(overloads_minus_v<double, short>);
	REQUIRE(overloads_minus_v<double, float>);
}

TEST_CASE("Test for multiply overloads of arithmetic types", "[type_traits_multiply_arithmetic]") {
	REQUIRE(overloads_multiply_v<short, int>);
	REQUIRE(overloads_multiply_v<int, int>);
	REQUIRE(overloads_multiply_v<float, int>);
	REQUIRE(overloads_multiply_v<int, short>);
	REQUIRE(overloads_multiply_v<int, float>);

	REQUIRE(overloads_multiply_v<short, double>);
	REQUIRE(overloads_multiply_v<double, double>);
	REQUIRE(overloads_multiply_v<float, double>);
	REQUIRE(overloads_multiply_v<double, short>);
	REQUIRE(overloads_multiply_v<double, float>);
}

TEST_CASE("Test for divide overloads of arithmetic types", "[type_traits_divide_arithmetic]") {
	REQUIRE(overloads_divide_v<short, int>);
	REQUIRE(overloads_divide_v<int, int>);
	REQUIRE(overloads_divide_v<float, int>);
	REQUIRE(overloads_divide_v<int, short>);
	REQUIRE(overloads_divide_v<int, float>);

	REQUIRE(overloads_divide_v<short, double>);
	REQUIRE(overloads_divide_v<double, double>);
	REQUIRE(overloads_divide_v<float, double>);
	REQUIRE(overloads_divide_v<double, short>);
	REQUIRE(overloads_divide_v<double, float>);
}

TEST_CASE("Test for bitwise_and overloads of arithmetic types", "[type_traits_bitwise_and_arithmetic]") {
	REQUIRE(overloads_bitwise_and_v<short, int>);
	REQUIRE(overloads_bitwise_and_v<int, int>);
	REQUIRE(overloads_bitwise_and_v<float, int> == false);
	REQUIRE(overloads_bitwise_and_v<int, short>);
	REQUIRE(overloads_bitwise_and_v<int, float> == false);
	REQUIRE(overloads_bitwise_and_v<int, double> == false);

	REQUIRE(overloads_bitwise_and_v<short, double> == false);
	REQUIRE(overloads_bitwise_and_v<double, double> == false);
	REQUIRE(overloads_bitwise_and_v<float, double> == false);
	REQUIRE(overloads_bitwise_and_v<double, short> == false);
	REQUIRE(overloads_bitwise_and_v<double, float> == false);
}

TEST_CASE("Test for bitwise_or overloads of arithmetic types", "[type_traits_bitwise_or_arithmetic]") {
	REQUIRE(overloads_bitwise_or_v<short, int>);
	REQUIRE(overloads_bitwise_or_v<int, int>);
	REQUIRE(overloads_bitwise_or_v<float, int> == false);
	REQUIRE(overloads_bitwise_or_v<int, short>);
	REQUIRE(overloads_bitwise_or_v<int, float> == false);
	REQUIRE(overloads_bitwise_or_v<int, double> == false);

	REQUIRE(overloads_bitwise_or_v<short, double> == false);
	REQUIRE(overloads_bitwise_or_v<double, double> == false);
	REQUIRE(overloads_bitwise_or_v<float, double> == false);
	REQUIRE(overloads_bitwise_or_v<double, short> == false);
	REQUIRE(overloads_bitwise_or_v<double, float> == false);
}

TEST_CASE("Test for bitwise_xor overloads of arithmetic types", "[type_traits_bitwise_xor_arithmetic]") {
	REQUIRE(overloads_bitwise_xor_v<short, int>);
	REQUIRE(overloads_bitwise_xor_v<int, int>);
	REQUIRE(overloads_bitwise_xor_v<float, int> == false);
	REQUIRE(overloads_bitwise_xor_v<int, short>);
	REQUIRE(overloads_bitwise_xor_v<int, float> == false);
	REQUIRE(overloads_bitwise_xor_v<int, double> == false);

	REQUIRE(overloads_bitwise_xor_v<short, double> == false);
	REQUIRE(overloads_bitwise_xor_v<double, double> == false);
	REQUIRE(overloads_bitwise_xor_v<float, double> == false);
	REQUIRE(overloads_bitwise_xor_v<double, short> == false);
	REQUIRE(overloads_bitwise_xor_v<double, float> == false);
}

TEST_CASE("Test for left_shift overloads of arithmetic types", "[type_traits_left_shift_arithmetic]") {
	REQUIRE(overloads_left_shift_v<short, int>);
	REQUIRE(overloads_left_shift_v<int, int>);
	REQUIRE(overloads_left_shift_v<float, int> == false);
	REQUIRE(overloads_left_shift_v<int, short>);
	REQUIRE(overloads_left_shift_v<int, float> == false);
	REQUIRE(overloads_left_shift_v<int, double> == false);

	REQUIRE(overloads_left_shift_v<short, double> == false);
	REQUIRE(overloads_left_shift_v<double, double> == false);
	REQUIRE(overloads_left_shift_v<float, double> == false);
	REQUIRE(overloads_left_shift_v<double, short> == false);
	REQUIRE(overloads_left_shift_v<double, float> == false);
}

TEST_CASE("Test for right_shift overloads of arithmetic types", "[type_traits_right_shift_arithmetic]") {
	REQUIRE(overloads_right_shift_v<short, int>);
	REQUIRE(overloads_right_shift_v<int, int>);
	REQUIRE(overloads_right_shift_v<float, int> == false);
	REQUIRE(overloads_right_shift_v<int, short>);
	REQUIRE(overloads_right_shift_v<int, float> == false);
	REQUIRE(overloads_right_shift_v<int, double> == false);

	REQUIRE(overloads_right_shift_v<short, double> == false);
	REQUIRE(overloads_right_shift_v<double, double> == false);
	REQUIRE(overloads_right_shift_v<float, double> == false);
	REQUIRE(overloads_right_shift_v<double, short> == false);
	REQUIRE(overloads_right_shift_v<double, float> == false);
}

TEST_CASE("Test for operator overloads of vector types", "[type_traits_vector]") {
	REQUIRE(overloads_plus_v<short, ivec1>);
	REQUIRE(overloads_plus_v<ivec1, ivec1>);
	REQUIRE(overloads_plus_v<float, ivec1>);
	REQUIRE(overloads_plus_v<ivec1, short>);
	REQUIRE(overloads_plus_v<ivec1, float>);

	REQUIRE(overloads_plus_v<short, ivec2>);
	REQUIRE(overloads_plus_v<ivec2, ivec2>);
	REQUIRE(overloads_plus_v<float, ivec2>);
	REQUIRE(overloads_plus_v<ivec2, short>);
	REQUIRE(overloads_plus_v<ivec2, float>);

	REQUIRE(overloads_plus_v<short, ivec3>);
	REQUIRE(overloads_plus_v<ivec3, ivec3>);
	REQUIRE(overloads_plus_v<float, ivec3>);
	REQUIRE(overloads_plus_v<ivec3, short>);
	REQUIRE(overloads_plus_v<ivec3, float>);

	REQUIRE(overloads_plus_v<short, ivec4>);
	REQUIRE(overloads_plus_v<ivec4, ivec4>);
	REQUIRE(overloads_plus_v<float, ivec4>);
	REQUIRE(overloads_plus_v<ivec4, short>);
	REQUIRE(overloads_plus_v<ivec4, float>);
}

struct S {};
struct Z {};
TEST_CASE("Test for operator overloads of failing types", "[type_traits_fails]") {
	REQUIRE(overloads_plus_v<S, S> == false);
	REQUIRE(overloads_plus_v<S, Z> == false);

	REQUIRE(overloads_plus_v<ivec2, ivec1> == false);
	REQUIRE(overloads_plus_v<ivec3, ivec1> == false);
	REQUIRE(overloads_plus_v<ivec4, ivec1> == false);
	REQUIRE(overloads_plus_v<ivec1, ivec2> == false);
	REQUIRE(overloads_plus_v<ivec3, ivec2> == false);
	REQUIRE(overloads_plus_v<ivec4, ivec2> == false);
	REQUIRE(overloads_plus_v<ivec1, ivec3> == false);
	REQUIRE(overloads_plus_v<ivec2, ivec3> == false);
	REQUIRE(overloads_plus_v<ivec4, ivec3> == false);
	REQUIRE(overloads_plus_v<ivec1, ivec4> == false);
	REQUIRE(overloads_plus_v<ivec2, ivec4> == false);
	REQUIRE(overloads_plus_v<ivec3, ivec4> == false);

	REQUIRE(overloads_plus_v<tmat1<int>, ivec1> == false);
	REQUIRE(overloads_plus_v<tmat1<int>, ivec2> == false);
	REQUIRE(overloads_plus_v<tmat1<int>, ivec3> == false);
	REQUIRE(overloads_plus_v<tmat1<int>, ivec4> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, ivec1> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, ivec2> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, ivec3> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, ivec4> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, ivec1> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, ivec2> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, ivec3> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, ivec4> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, ivec1> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, ivec2> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, ivec3> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, ivec4> == false);

	REQUIRE(overloads_plus_v<tmat1<int>, tmat2<int>> == false);
	REQUIRE(overloads_plus_v<tmat1<int>, tmat3<int>> == false);
	REQUIRE(overloads_plus_v<tmat1<int>, tmat4<int>> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, tmat1<int>> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, tmat3<int>> == false);
	REQUIRE(overloads_plus_v<tmat2<int>, tmat4<int>> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, tmat1<int>> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, tmat2<int>> == false);
	REQUIRE(overloads_plus_v<tmat3<int>, tmat4<int>> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, tmat1<int>> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, tmat2<int>> == false);
	REQUIRE(overloads_plus_v<tmat4<int>, tmat3<int>> == false);
}
