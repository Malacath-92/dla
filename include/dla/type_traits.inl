#pragma once

#include "type_traits.h"

namespace dla {
	template<class Name, std::intmax_t Num, std::intmax_t Den>
	struct unit_tag;
	template<class Tag>
	struct base_unit;
	template<class... Tags>
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
            static auto test(int) -> decltype(std::declval<V>() op std::declval<W>(), std::true_type()); \
            template<typename, typename> \
            static auto test(...) -> std::false_type; \
			template<class V> \
			using const_ref_t = std::add_const_t<std::add_lvalue_reference_t<std::decay_t<V>>>; \
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

	template<class Tag>
    struct is_packed<base_unit<Tag>> {
        static constexpr bool value = sizeof(base_unit<Tag>) == sizeof(float);
    };
	template<class... Tags>
    struct is_packed<comp_unit<Tags...>> {
        static constexpr bool value = sizeof(comp_unit<Tags...>) == sizeof(float);
    };

	template<class T>
	struct is_unit_tag : std::false_type {};
    template<class Name, std::intmax_t Num, std::intmax_t Den>
    struct is_unit_tag<unit_tag<Name, Num, Den>> : std::true_type {};
	template<class T>
	struct is_base_unit : std::false_type {};
	template<class Tag>
	struct is_base_unit<base_unit<Tag>> : std::true_type {};
	template<class T>
	struct is_comp_unit : std::false_type {};
	template<class... Tags>
	struct is_comp_unit<comp_unit<Tags...>> : std::true_type {};
    
    template<class T, std::size_t N>
    struct is_packed<vec<T, N>> {
        static constexpr bool value = sizeof(vec<T, N>) == sizeof(T) * N;
    };
    template<class T, std::size_t N, std::size_t M>
    struct is_packed<mat<T, N, M>> {
        static constexpr bool value = sizeof(mat<T, N, M>) == sizeof(T) * N * M;
    };
}
