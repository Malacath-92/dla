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

using imat2x4 = tmat2x4<int>;
using imat4x2 = tmat4x2<int>;

DLA_TEST_CONSTEXPR auto mat2 = imat2({ 1, 2 }, { 3, 4 });
DLA_TEST_CONSTEXPR auto mat3 = imat3({ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 });
DLA_TEST_CONSTEXPR auto mat4 = imat4({ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16});

DLA_TEST_CONSTEXPR auto mat2x4 = imat2x4({ 1, 2, 3, 4 }, { 5, 6, 7, 8 });
DLA_TEST_CONSTEXPR auto mat4x2 = imat4x2({ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 });

DLA_TEST_CONSTEXPR auto mat2_sqr_expected = imat2({ 7, 10 }, { 15, 22 });
DLA_TEST_CONSTEXPR auto mat3_sqr_expected = imat3({ 30, 36, 42 }, { 66, 81, 96 }, { 102, 126, 150 });
DLA_TEST_CONSTEXPR auto mat4_sqr_expected = imat4({ 90, 100, 110, 120 }, { 202, 228, 254, 280 }, { 314, 356, 398, 440 }, { 426, 484, 542, 600 });

DLA_TEST_CONSTEXPR auto mat2_expected = imat2({ 50, 60 }, { 114, 140 });
DLA_TEST_CONSTEXPR auto mat4_expected = imat4({ 11, 14, 17, 20 }, { 23, 30, 37, 44 }, { 35, 46, 57, 68 }, { 47, 62, 77, 92 });

DLA_TEST_CONSTEXPR auto mat2_sqr = dla::matrix_product(mat2, mat2);
DLA_TEST_CONSTEXPR auto mat3_sqr = dla::matrix_product(mat3, mat3);
DLA_TEST_CONSTEXPR auto mat4_sqr = dla::matrix_product(mat4, mat4);

DLA_TEST_CONSTEXPR auto mat2_prod = dla::matrix_product(mat2x4, mat4x2);
DLA_TEST_CONSTEXPR auto mat4_prod = dla::matrix_product(mat4x2, mat2x4);

TEST_CASE("Compute matrix_product of matrices", "[matrix_matrix_product]") {
    REQUIRE(mat2_sqr == mat2_sqr_expected);
    REQUIRE(mat3_sqr == mat3_sqr_expected);
    REQUIRE(mat4_sqr == mat4_sqr_expected);
    REQUIRE(mat2_prod == mat2_expected);
    REQUIRE(mat4_prod == mat4_expected);
}
