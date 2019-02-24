#include <vector.h>
#include <matrix.h>

#include <type_traits>

int main() {
	using namespace dla;
	using imat3x4 = tmat3x4<int>;
	using imat4x3 = tmat4x3<int>;
	using imat3 = tmat3<int>;
	using imat4 = tmat4<int>;
	constexpr auto matrix3 = imat3({ 0, 1, 2 }, { 9, 16, 25 }, { -3, -5, -7 });
	constexpr auto matrix3x4 = imat3x4({ 0, 1, 2, 3 }, { 9, 16, 25, 36 }, { -3, -5, -7, -11 });
	constexpr auto matrix4x3 = imat4x3({ 0, 1, 2 }, { 9, 16, 25 }, { -3, -5, -7 }, { 10, 11, 12 });
	constexpr auto vector3 = ivec3(1, -3, 5);
	constexpr auto vector4 = ivec4(-1, 3, -5, 7);

	constexpr auto matrix3_dot_expected = imat3({3, 6, 11}, {69, 140, 243}, {-24, -48, -82});
	constexpr auto matrix3_other_dot_expected = imat3({33, 39, 47}, {429, 536, 675}, {-134, -169, -214});
	constexpr auto matrix4_dot_expected = imat4({3, 6, 11, 14}, {69, 140, 243, 328}, {-24, -48, -82, -112}, {63, 126, 211, 294});
	constexpr auto mat3_vec3_dot_expected = dla::ivec3(7, 86, -23);
	constexpr auto vec3_mat3_dot_expected = dla::ivec3(-42, -72, -108);
	constexpr auto mat_vec3_dot_expected = dla::ivec4(7, 86, -23, 37);
	constexpr auto vec3_mat_dot_expected = dla::ivec4(-42, -72, -108, -160);
	constexpr auto mat_vec4_dot_expected = dla::ivec3(14, 166, -54);
	constexpr auto vec4_mat_dot_expected = dla::ivec3(112, 149, 192);

	int error = 0;

	error += !std::is_same_v<imat3, decltype(dla::dot(imat3x4{}, imat4x3{}))>;
	error += !std::is_same_v<imat4, decltype(dla::dot(imat4x3{}, imat3x4{}))>;

	constexpr auto matrix3_dot = dla::dot(matrix3, matrix3);
	constexpr auto matrix3_other_dot = dla::dot(matrix3x4, matrix4x3);
	constexpr auto matrix4_dot = dla::dot(matrix4x3, matrix3x4);
	constexpr auto mat3_vec3_dot = dla::dot(matrix3, vector3);
	constexpr auto vec3_mat3_dot = dla::dot(vector3, matrix3);
	constexpr auto mat_vec3_dot = dla::dot(matrix4x3, vector3);
	constexpr auto vec3_mat_dot = dla::dot(vector3, matrix3x4);
	constexpr auto mat_vec4_dot = dla::dot(matrix3x4, vector4);
	constexpr auto vec4_mat_dot = dla::dot(vector4, matrix4x3);

	error += matrix3_dot != matrix3_dot_expected;
	error += matrix3_other_dot != matrix3_other_dot_expected;
	error += matrix4_dot != matrix4_dot_expected;
	error += mat3_vec3_dot != mat3_vec3_dot_expected;
	error += vec3_mat3_dot != vec3_mat3_dot_expected;
	error += mat_vec3_dot != mat_vec3_dot_expected;
	error += vec3_mat_dot != vec3_mat_dot_expected;
	error += mat_vec4_dot != mat_vec4_dot_expected;
	error += vec4_mat_dot != vec4_mat_dot_expected;

	return error;
}
