#include "common.h"

#include <vector.h>
#include <matrix.h>
#include <to_string.h>

#include <type_traits>

#include <catch2/catch.hpp>

using namespace dla;
using imat2 = tmat2<int>;
using imat3 = tmat3<int>;
using imat4 = tmat4<int>;

DLA_TEST_CONSTEXPR auto matrix2x2_expected = imat2({ 1, 0 }, { 0, 2 });
DLA_TEST_CONSTEXPR auto matrix3x3_expected = imat3({ 1, 0, 0 }, { 0, 2, 0 }, { 0, 0, 3 });
DLA_TEST_CONSTEXPR auto matrix4x4_expected = imat4({ 1, 0, 0, 0 }, { 0, 2, 0, 0 }, { 0, 0, 3, 0 }, { 0, 0, 0, 4 });

DLA_TEST_CONSTEXPR auto matrix2x2 = diagonal(vec(1, 2));
DLA_TEST_CONSTEXPR auto matrix3x3 = diagonal(vec(1, 2, 3));
DLA_TEST_CONSTEXPR auto matrix4x4 = diagonal(vec(1, 2, 3, 4));

TEST_CASE("Generate diagonal matrices", "[matrix_diagonal]") {
    REQUIRE(matrix2x2 == matrix2x2_expected);
    REQUIRE(matrix3x3 == matrix3x3_expected);
    REQUIRE(matrix4x4 == matrix4x4_expected);
}
