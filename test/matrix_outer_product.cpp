#include "common.h"

#include <vector.h>
#include <matrix.h>
#include <to_string.h>

#include <type_traits>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using imat2x3 = tmat2x3<int>;
using imat2x4 = tmat2x4<int>;
using imat4x2 = tmat4x2<int>;
using imat3x4 = tmat3x4<int>;
using imat4 = tmat4<int>;

DLA_TEST_CONSTEXPR auto vector2 = ivec2(1, 125);
DLA_TEST_CONSTEXPR auto vector3 = ivec3(1, -3, 5);
DLA_TEST_CONSTEXPR auto vector4 = ivec4(-1, 3, -5, 7);
DLA_TEST_CONSTEXPR auto vector4_other = ivec4(0, 0, 2, -11);

DLA_TEST_CONSTEXPR auto matrix2x3_expected = imat2x3({1, -3, 5}, {125, -375, 625});
DLA_TEST_CONSTEXPR auto matrix2x4_expected = imat2x4({ -1, 3, -5, 7 }, { -125, 375, -625, 875 });
DLA_TEST_CONSTEXPR auto matrix4x2_expected = imat4x2({ -1, -125 }, { 3, 375 }, { -5, -625 }, { 7, 875 });
DLA_TEST_CONSTEXPR auto matrix3x4_expected = imat3x4({ -1, 3, -5, 7}, { 3, -9, 15, -21}, { -5, 15, -25, 35});
DLA_TEST_CONSTEXPR auto matrix4x4_expected = imat4({ 1, -3, 5, -7 }, { -3, 9, -15, 21 }, { 5, -15, 25, -35 }, { -7, 21, -35, 49 });
DLA_TEST_CONSTEXPR auto matrix4x4_other_expected = imat4({ 0, 0, -2, 11 }, { 0, 0, 6, -33 }, { 0, 0, -10, 55 }, { 0, 0, 14, -77 });

DLA_TEST_CONSTEXPR auto matrix2x3 = outer_product(vector2, vector3);
DLA_TEST_CONSTEXPR auto matrix2x4 = outer_product(vector2, vector4);
DLA_TEST_CONSTEXPR auto matrix4x2 = outer_product(vector4, vector2);
DLA_TEST_CONSTEXPR auto matrix3x4 = outer_product(vector3, vector4);
DLA_TEST_CONSTEXPR auto matrix4x4 = outer_product(vector4, vector4);
DLA_TEST_CONSTEXPR auto matrix4x4_other = outer_product(vector4, vector4_other);

TEST_CASE("Compute outer_product of vectors", "[matrix_outer_product]") {
    REQUIRE(matrix2x3 == matrix2x3_expected);
    REQUIRE(matrix2x4 == matrix2x4_expected);
    REQUIRE(matrix4x2 == matrix4x2_expected);
    REQUIRE(matrix3x4 == matrix3x4_expected);
    REQUIRE(matrix4x4 == matrix4x4_expected);
    REQUIRE(matrix4x4_other == matrix4x4_other_expected);
}
