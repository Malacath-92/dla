#include "common.h"

#include <vector.h>
#include <matrix.h>
#include <to_string.h>

#include <type_traits>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using imat3x4 = tmat3x4<int>;
using imat4x3 = tmat4x3<int>;
using imat3 = tmat3<int>;
using imat4 = tmat4<int>;

DLA_TEST_CONSTEXPR auto matrix3 = imat3({ 0, 1, 2 }, { 9, 16, 25 }, { -3, -5, -7 });
DLA_TEST_CONSTEXPR auto matrix3x4 = imat3x4({ 0, 1, 2, 3 }, { 9, 16, 25, 36 }, { -3, -5, -7, -11 });
DLA_TEST_CONSTEXPR auto matrix4x3 = imat4x3({ 0, 1, 2 }, { 9, 16, 25 }, { -3, -5, -7 }, { 10, 11, 12 });
DLA_TEST_CONSTEXPR auto vector3 = ivec3(1, -3, 5);
DLA_TEST_CONSTEXPR auto vector4 = ivec4(-1, 3, -5, 7);

DLA_TEST_CONSTEXPR auto matrix3_dot_expected = imat3({3, 6, 11}, {69, 140, 243}, {-24, -48, -82});
DLA_TEST_CONSTEXPR auto matrix3_other_dot_expected = imat3({33, 39, 47}, {429, 536, 675}, {-134, -169, -214});
DLA_TEST_CONSTEXPR auto matrix4_dot_expected = imat4({3, 6, 11, 14}, {69, 140, 243, 328}, {-24, -48, -82, -112}, {63, 126, 211, 294});
DLA_TEST_CONSTEXPR auto mat3_vec3_dot_expected = dla::ivec3(7, 86, -23);
DLA_TEST_CONSTEXPR auto vec3_mat3_dot_expected = dla::ivec3(-42, -72, -108);
DLA_TEST_CONSTEXPR auto mat_vec3_dot_expected = dla::ivec4(7, 86, -23, 37);
DLA_TEST_CONSTEXPR auto vec3_mat_dot_expected = dla::ivec4(-42, -72, -108, -160);
DLA_TEST_CONSTEXPR auto mat_vec4_dot_expected = dla::ivec3(14, 166, -54);
DLA_TEST_CONSTEXPR auto vec4_mat_dot_expected = dla::ivec3(112, 149, 192);

DLA_TEST_CONSTEXPR auto matrix3_dot = dla::dot(matrix3, matrix3);
DLA_TEST_CONSTEXPR auto matrix3_other_dot = dla::dot(matrix3x4, matrix4x3);
DLA_TEST_CONSTEXPR auto matrix4_dot = dla::dot(matrix4x3, matrix3x4);
DLA_TEST_CONSTEXPR auto mat3_vec3_dot = dla::dot(matrix3, vector3);
DLA_TEST_CONSTEXPR auto vec3_mat3_dot = dla::dot(vector3, matrix3);
DLA_TEST_CONSTEXPR auto mat_vec3_dot = dla::dot(matrix4x3, vector3);
DLA_TEST_CONSTEXPR auto vec3_mat_dot = dla::dot(vector3, matrix3x4);
DLA_TEST_CONSTEXPR auto mat_vec4_dot = dla::dot(matrix3x4, vector4);
DLA_TEST_CONSTEXPR auto vec4_mat_dot = dla::dot(vector4, matrix4x3);

TEST_CASE("Compute dot productes of matrices with matrices/vectors", "[matrix_dot]") {
	REQUIRE(std::is_same_v<imat3, decltype(dla::dot(imat3x4{}, imat4x3{}))>);
	REQUIRE(std::is_same_v<imat4, decltype(dla::dot(imat4x3{}, imat3x4{}))>);

	REQUIRE(matrix3_dot == matrix3_dot_expected);
	REQUIRE(matrix3_other_dot == matrix3_other_dot_expected);
	REQUIRE(matrix4_dot == matrix4_dot_expected);
	REQUIRE(mat3_vec3_dot == mat3_vec3_dot_expected);
	REQUIRE(vec3_mat3_dot == vec3_mat3_dot_expected);
	REQUIRE(mat_vec3_dot == mat_vec3_dot_expected);
	REQUIRE(vec3_mat_dot == vec3_mat_dot_expected);
	REQUIRE(mat_vec4_dot == mat_vec4_dot_expected);
	REQUIRE(vec4_mat_dot == vec4_mat_dot_expected);
}
