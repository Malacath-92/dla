#include "common.h"

#include <dla/vector.h>
#include <dla/matrix.h>
#include <dla/type_traits.h>

#include <catch2/catch.hpp>

using namespace dla;

TEST_CASE("Test if scalar are recognized", "[type_traits_scalar]") {
	REQUIRE(is_scalar_v<int>);
	REQUIRE(is_scalar_v<float>);
	REQUIRE(is_scalar_v<double>);
    
	REQUIRE(!is_scalar_v<ivec1>);
	REQUIRE(!is_scalar_v<vec1>);
	REQUIRE(!is_scalar_v<dvec1>);
    
	REQUIRE(!is_scalar_v<ivec2>);
	REQUIRE(!is_scalar_v<vec2>);
	REQUIRE(!is_scalar_v<dvec2>);
    
	REQUIRE(!is_scalar_v<ivec3>);
	REQUIRE(!is_scalar_v<vec3>);
	REQUIRE(!is_scalar_v<dvec3>);
    
	REQUIRE(!is_scalar_v<ivec4>);
	REQUIRE(!is_scalar_v<vec4>);
	REQUIRE(!is_scalar_v<dvec4>);
    
	REQUIRE(!is_scalar_v<tmat1<float>>);
	REQUIRE(!is_scalar_v<tmat2<float>>);
	REQUIRE(!is_scalar_v<tmat3<float>>);
	REQUIRE(!is_scalar_v<tmat4<float>>);
}
