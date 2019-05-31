#pragma once

namespace dla {
	template<class T, class U>
	struct overloads_plus;
	template<class T, class U>
	struct overloads_minus;
	template<class T, class U>
	struct overloads_multiply;
	template<class T, class U>
	struct overloads_divide;
	template<class T, class U>
	struct overloads_modulo;
	template<class T, class U>
	struct overloads_bitwise_and;
	template<class T, class U>
	struct overloads_bitwise_or;
	template<class T, class U>
	struct overloads_bitwise_xor;
	template<class T, class U>
	struct overloads_left_shift;
	template<class T, class U>
	struct overloads_right_shift;

    template<class T>
    struct is_packed;
    

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
    
    template<class T>
    inline constexpr auto is_packed_v = is_packed<T>::value;
}

#include "type_traits.inl"
