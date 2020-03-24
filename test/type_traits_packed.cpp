#include "common.h"

#include <dla/vector.h>
#include <dla/matrix.h>
#include <dla/units.h>
#include <dla/type_traits.h>

#include <catch2/catch.hpp>

using namespace dla;

TEST_CASE("Test if vector and matrix types are packed tightly", "[type_traits_packed]") {
    REQUIRE(is_packed_v<length_unit>);
    REQUIRE(is_packed_v<velocity_unit>);
    REQUIRE(is_packed_v<force_unit>);

    REQUIRE(is_packed_v<vec1>);
    REQUIRE(is_packed_v<vec2>);
    REQUIRE(is_packed_v<vec3>);
    REQUIRE(is_packed_v<vec4>);

    REQUIRE(is_packed_v<tvec1<length_unit>>);
    REQUIRE(is_packed_v<tvec2<length_unit>>);
    REQUIRE(is_packed_v<tvec3<length_unit>>);
    REQUIRE(is_packed_v<tvec4<length_unit>>);

    REQUIRE(is_packed_v<tvec1<velocity_unit>>);
    REQUIRE(is_packed_v<tvec2<velocity_unit>>);
    REQUIRE(is_packed_v<tvec3<velocity_unit>>);
    REQUIRE(is_packed_v<tvec4<velocity_unit>>);

    REQUIRE(is_packed_v<tmat1<short>>);
    REQUIRE(is_packed_v<tmat1<float>>);
    REQUIRE(is_packed_v<tmat1<double>>);
    
    REQUIRE(is_packed_v<tmat2<short>>);
    REQUIRE(is_packed_v<tmat2<float>>);
    REQUIRE(is_packed_v<tmat2<double>>);
    
    REQUIRE(is_packed_v<tmat3<short>>);
    REQUIRE(is_packed_v<tmat3<float>>);
    REQUIRE(is_packed_v<tmat3<double>>);
    
    REQUIRE(is_packed_v<tmat4<short>>);
    REQUIRE(is_packed_v<tmat4<float>>);
    REQUIRE(is_packed_v<tmat4<double>>);
}
