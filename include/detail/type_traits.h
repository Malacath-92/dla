#pragma once

#include <type_traits>

namespace dla::detail {
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

	template<class T, class U>
	inline constexpr auto overloads_plus_v = overloads_plus<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_minus_v = overloads_minus<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_multiply_v = overloads_multiply<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_divide_v = overloads_divide<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_modulo_v = overloads_modulo<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_bitwise_and_v = overloads_bitwise_and<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_bitwise_or_v = overloads_bitwise_or<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_bitwise_xor_v = overloads_bitwise_xor<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_left_shift_v = overloads_left_shift<T, U>::value;
	template<class T, class U>
	inline constexpr auto overloads_right_shift_v = overloads_right_shift<T, U>::value;
}
