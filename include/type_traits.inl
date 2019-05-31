#pragma once

#include "type_traits.h"

namespace dla {
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;

    template<class T, std::size_t N>
    struct vec;
    template<class T, std::size_t N, std::size_t M>
    struct mat;
    
#define MAKE_OVERLOAD_TEST_STRUCT(opName, op) \
	template<class T, class U> \
	struct overloads_##opName { \
		private: \
            template<typename V, typename W> \
            static auto test(int) -> decltype(std::declval<V&>() op std::declval<W>(), std::true_type()); \
            template<typename, typename> \
            static auto test(...) -> std::false_type; \
			template<class V> \
			using const_ref_t = std::add_const_t<std::add_lvalue_reference_t<T>>; \
        public: \
            static constexpr bool value = decltype(test<const_ref_t<T>, const_ref_t<U>>(0))::value; \
	};
    MAKE_OVERLOAD_TEST_STRUCT(plus, +)
    MAKE_OVERLOAD_TEST_STRUCT(minus, -)
    MAKE_OVERLOAD_TEST_STRUCT(multiply, *)
    MAKE_OVERLOAD_TEST_STRUCT(divide, /)
    MAKE_OVERLOAD_TEST_STRUCT(modulo, %)
    MAKE_OVERLOAD_TEST_STRUCT(bitwise_and, &)
    MAKE_OVERLOAD_TEST_STRUCT(bitwise_or, |)
    MAKE_OVERLOAD_TEST_STRUCT(bitwise_xor, ^)
    MAKE_OVERLOAD_TEST_STRUCT(left_shift, <<)
    MAKE_OVERLOAD_TEST_STRUCT(right_shift, >>)
#undef MAKE_OVERLOAD_TEST_STRUCT
    
    template<class T>
    struct is_scalar {
        static constexpr bool value = true;
    };
    template<class T, std::size_t N>
    struct is_scalar<vec<T, N>> {
        static constexpr bool value = false;
    };
    template<class T, std::size_t N, std::size_t M>
    struct is_scalar<mat<T, N, M>> {
        static constexpr bool value = false;
    };

	template<class Tag, std::intmax_t Num, std::intmax_t Den>
    struct is_packed<base_unit<Tag, Num, Den>> {
        static constexpr bool value = sizeof(base_unit<Tag, Num, Den>) == sizeof(float);
    };
	template<class... Units>
    struct is_packed<comp_unit<Units...>> {
        static constexpr bool value = sizeof(comp_unit<Units...>) == sizeof(float);
    };
    
    template<class T, std::size_t N>
    struct is_packed<vec<T, N>> {
        static constexpr bool value = sizeof(vec<T, N>) == sizeof(T) * N;
    };
    template<class T, std::size_t N, std::size_t M>
    struct is_packed<mat<T, N, M>> {
        static constexpr bool value = sizeof(mat<T, N, M>) == sizeof(T) * N * M;
    };
}
