#include "vector.h"
#include "matrix.h"
#include "units.h"
#include "utility.h"

int main() {
	using namespace dla;

    static_assert(is_packed_v<length_unit>);
    static_assert(is_packed_v<velocity_unit>);
    static_assert(is_packed_v<force_unit>);

    static_assert(is_packed_v<vec1>);
    static_assert(is_packed_v<vec2>);
    static_assert(is_packed_v<vec3>);
    static_assert(is_packed_v<vec4>);

    static_assert(is_packed_v<tvec1<length_unit>>);
    static_assert(is_packed_v<tvec2<length_unit>>);
    static_assert(is_packed_v<tvec3<length_unit>>);
    static_assert(is_packed_v<tvec4<length_unit>>);

    static_assert(is_packed_v<tvec1<velocity_unit>>);
    static_assert(is_packed_v<tvec2<velocity_unit>>);
    static_assert(is_packed_v<tvec3<velocity_unit>>);
    static_assert(is_packed_v<tvec4<velocity_unit>>);

    static_assert(is_packed_v<tmat1<short>>);
    static_assert(is_packed_v<tmat1<float>>);
    static_assert(is_packed_v<tmat1<double>>);
    
    static_assert(is_packed_v<tmat2<short>>);
    static_assert(is_packed_v<tmat2<float>>);
    static_assert(is_packed_v<tmat2<double>>);
    
    static_assert(is_packed_v<tmat3<short>>);
    static_assert(is_packed_v<tmat3<float>>);
    static_assert(is_packed_v<tmat3<double>>);
    
    static_assert(is_packed_v<tmat4<short>>);
    static_assert(is_packed_v<tmat4<float>>);
    static_assert(is_packed_v<tmat4<double>>);

    return 0;
}