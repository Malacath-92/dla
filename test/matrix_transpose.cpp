#include "common.h"

#include <vector.h>
#include <matrix.h>
#include <to_string.h>

#include <type_traits>

#include <catch2/catch.hpp>

using namespace dla;
using imat2x3 = tmat2x3<int>;
using imat2x4 = tmat2x4<int>;
using imat3x4 = tmat3x4<int>;
using imat3x2 = tmat3x2<int>;
using imat4x2 = tmat4x2<int>;
using imat4x3 = tmat4x3<int>;
using imat2 = tmat2<int>;
using imat3 = tmat3<int>;
using imat4 = tmat4<int>;

DLA_TEST_CONSTEXPR auto matrix2x2_expected = imat2({ 1, 3 }, { 2, 4 });
DLA_TEST_CONSTEXPR auto matrix2x3_expected = imat3x2({ 1, 3 }, { 2, 4 }, { 5, 6 });
DLA_TEST_CONSTEXPR auto matrix2x4_expected = imat4x2({ 1, 3 }, { 2, 4 }, { 5, 6 }, { 7, 8 });
DLA_TEST_CONSTEXPR auto matrix3x3_expected = imat3({ 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 });
DLA_TEST_CONSTEXPR auto matrix3x4_expected = imat4x3({ 1, 4, 7 }, { 2, 5, 8 }, { 3, 6, 9 }, { 10, 11, 12 });
DLA_TEST_CONSTEXPR auto matrix4x4_expected = imat4({ 1, 5, 9, 13 }, { 2, 6, 10, 14 }, { 3, 7, 11, 15 }, { 4, 8, 12, 16 });

DLA_TEST_CONSTEXPR auto matrix2x2 = transpose(imat2({ 1, 2 }, { 3, 4 }));
DLA_TEST_CONSTEXPR auto matrix2x3 = transpose(imat2x3({ 1, 2, 5 }, { 3, 4, 6 }));
DLA_TEST_CONSTEXPR auto matrix2x4 = transpose(imat2x4({ 1, 2, 5, 7 }, { 3, 4, 6, 8 }));
DLA_TEST_CONSTEXPR auto matrix3x3 = transpose(imat3({ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }));
DLA_TEST_CONSTEXPR auto matrix3x4 = transpose(imat3x4({ 1, 2, 3, 10 }, { 4, 5, 6, 11 }, { 7, 8, 9, 12 }));
DLA_TEST_CONSTEXPR auto matrix4x4 = transpose(imat4({ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }));

TEST_CASE("Compute transpose of matrices", "[matrix_transpose]") {
    REQUIRE(matrix2x2 == matrix2x2_expected);
    REQUIRE(matrix2x3 == matrix2x3_expected);
    REQUIRE(matrix2x4 == matrix2x4_expected);
    REQUIRE(matrix3x3 == matrix3x3_expected);
    REQUIRE(matrix3x4 == matrix3x4_expected);
    REQUIRE(matrix4x4 == matrix4x4_expected);
}
