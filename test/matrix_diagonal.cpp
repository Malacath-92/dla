#include "common.h"

#include <dla/vector.h>
#include <dla/matrix.h>
#include <dla/to_string.h>

#include <type_traits>

#include <catch2/catch_test_macros.hpp>

using namespace dla;
using imat2 = tmat2<int>;
using imat3 = tmat3<int>;
using imat4 = tmat4<int>;
using imat2x3 = tmat2x3<int>;
using imat2x4 = tmat2x4<int>;
using imat3x2 = tmat3x2<int>;
using imat4x2 = tmat4x2<int>;

DLA_TEST_CONSTEXPR auto matrix2x2_expected = imat2({ 1, 0 }, { 0, 2 });
DLA_TEST_CONSTEXPR auto matrix3x3_expected = imat3({ 1, 0, 0 }, { 0, 2, 0 }, { 0, 0, 3 });
DLA_TEST_CONSTEXPR auto matrix4x4_expected = imat4({ 1, 0, 0, 0 }, { 0, 2, 0, 0 }, { 0, 0, 3, 0 }, { 0, 0, 0, 4 });
DLA_TEST_CONSTEXPR auto matrix2x3_expected = imat2x3({ 1, 0, 0 }, { 0, 2, 0 });
DLA_TEST_CONSTEXPR auto matrix2x4_expected = imat2x4({ 1, 0, 0, 0 }, { 0, 2, 0, 0 });
DLA_TEST_CONSTEXPR auto matrix3x2_expected = imat3x2({ 1, 0 }, { 0, 2 }, { 0, 0 });
DLA_TEST_CONSTEXPR auto matrix4x2_expected = imat4x2({ 1, 0 }, { 0, 2 }, { 0, 0 }, { 0, 0 });

DLA_TEST_CONSTEXPR auto matrix2x2 = diagonal(vec(1, 2));
DLA_TEST_CONSTEXPR auto matrix3x3 = diagonal(vec(1, 2, 3));
DLA_TEST_CONSTEXPR auto matrix4x4 = diagonal(vec(1, 2, 3, 4));
DLA_TEST_CONSTEXPR auto matrix2x3 = diagonal<2, 3>(vec(1, 2));
DLA_TEST_CONSTEXPR auto matrix2x4 = diagonal<2, 4>(vec(1, 2, 3));
DLA_TEST_CONSTEXPR auto matrix3x2 = diagonal<3, 2>(vec(1, 2, 3, 4));
DLA_TEST_CONSTEXPR auto matrix4x2 = diagonal<4, 2>(vec(1, 2, 3, 4));

TEST_CASE("Generate diagonal matrices", "[matrix_diagonal]") {
    REQUIRE(matrix2x2 == matrix2x2_expected);
    REQUIRE(matrix3x3 == matrix3x3_expected);
    REQUIRE(matrix4x4 == matrix4x4_expected);
    REQUIRE(matrix2x3 == matrix2x3_expected);
    REQUIRE(matrix2x4 == matrix2x4_expected);
    REQUIRE(matrix3x2 == matrix3x2_expected);
    REQUIRE(matrix4x2 == matrix4x2_expected);
}
