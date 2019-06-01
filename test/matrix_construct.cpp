#include <vector.h>
#include <matrix.h>
#include <to_string.h>

#include <type_traits>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace dla;
using imat2 = tmat2<int>;
using imat3 = tmat3<int>;
using imat4 = tmat4<int>;
using imat2x3 = tmat2x3<int>;
using imat3x4 = tmat3x4<int>;
using imat4x2 = tmat4x2<int>;

using umat2 = tmat2<unsigned int>;
using umat3 = tmat3<unsigned int>;
using umat4 = tmat4<unsigned int>;

constexpr auto matrix2x2_diag_expected = imat2({ 1, 0 }, { 0, 1 });
constexpr auto matrix2x2_fill_expected = imat2({ 1, 1 }, { 1, 1 });
constexpr auto matrix3x3_diag_expected = imat3({ 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 });
constexpr auto matrix3x3_fill_expected = imat3({ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 });
constexpr auto matrix4x4_diag_expected = imat4({ 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 });
constexpr auto matrix4x4_fill_expected = imat4({ 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 });
constexpr auto matrix2x3_expected = imat2x3({ 1, 1, 1 }, { 1, 1, 1 });
constexpr auto matrix3x4_expected = imat3x4({ 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 });
constexpr auto matrix4x2_expected = imat4x2({ 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 });

constexpr auto matrix2x2_diag = imat2(1);
constexpr auto matrix2x2_fill = imat2(1, matrix_fill);
constexpr auto matrix3x3_diag = imat3(1);
constexpr auto matrix3x3_fill = imat3(1, matrix_fill);
constexpr auto matrix4x4_diag = imat4(1);
constexpr auto matrix4x4_fill = imat4(1, matrix_fill);
constexpr auto matrix2x3 = imat2x3(1);
constexpr auto matrix3x4 = imat3x4(1);
constexpr auto matrix4x2 = imat4x2(1);

constexpr auto matrix2x2_conv_expected = umat2({ 1u, 0u }, { 0u, 1u });
constexpr auto matrix3x3_conv_expected = umat3({ 1u, 0u, 0u }, { 0u, 1u, 0u }, { 0u, 0u, 1u });
constexpr auto matrix4x4_conv_expected = umat4({ 1u, 0u, 0u, 0u }, { 0u, 1u, 0u, 0u }, { 0u, 0u, 1u, 0u }, { 0u, 0u, 0u, 1u });

#ifdef _MSC_VER
/*constexpr*/ auto matrix2x2_conv = umat2(matrix2x2_diag);
/*constexpr*/ auto matrix3x3_conv = umat3(matrix3x3_diag);
/*constexpr*/ auto matrix4x4_conv = umat4(matrix4x4_diag);
#else
constexpr auto matrix2x2_conv = umat2(matrix2x2_diag);
constexpr auto matrix3x3_conv = umat3(matrix3x3_diag);
constexpr auto matrix4x4_conv = umat4(matrix4x4_diag);
#endif

TEST_CASE("Generate matrices from single arguments", "[matrix_construct_single]") {
    REQUIRE(matrix2x2_diag == matrix2x2_diag_expected);
    REQUIRE(matrix2x2_fill == matrix2x2_fill_expected);
    REQUIRE(matrix3x3_diag == matrix3x3_diag_expected);
    REQUIRE(matrix3x3_fill == matrix3x3_fill_expected);
    REQUIRE(matrix4x4_diag == matrix4x4_diag_expected);
    REQUIRE(matrix4x4_fill == matrix4x4_fill_expected);
    REQUIRE(matrix2x3 == matrix2x3_expected);
    REQUIRE(matrix3x4 == matrix3x4_expected);
    REQUIRE(matrix4x2 == matrix4x2_expected);
}

TEST_CASE("Copy construct matrices from other underlying type", "[matrix_construct_convert]") {
    REQUIRE(matrix2x2_conv == matrix2x2_conv_expected);
    REQUIRE(matrix3x3_conv == matrix3x3_conv_expected);
    REQUIRE(matrix4x4_conv == matrix4x4_conv_expected);
}
