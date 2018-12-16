#pragma once

#include <tuple>
#include <utility>

namespace unit::detail {
	// Implementation from https://goo.gl/ZHZ6Zx
	// Swap types at index I and J in the template argument Tuple
	template<class Tuple, std::size_t I, std::size_t J>
	class tuple_element_swap {
		template<std::size_t K>
		using swapped_tuple_element_t = std::tuple_element_t<K != I && K != J ? K : K == I ? J : I, Tuple>;

		template <class IndexSequence>
		struct tuple_element_swap_impl;
		template <std::size_t... Is>
		struct tuple_element_swap_impl<std::index_sequence<Is...>> {
			using type = std::tuple<swapped_tuple_element_t<Is>...>;
		};

	public:
		using type = typename tuple_element_swap_impl<std::make_index_sequence<std::tuple_size<Tuple>::value>>::type;
	};
	template<class Tuple, std::size_t I, std::size_t J>
	using tuple_element_swap_t = typename tuple_element_swap<Tuple, I, J>::type;

	// Selection sort template argument tuple's variadic template's types
	template <template <class, class> class Comparator, class Tuple>
	class tuple_selection_sort {
		// Selection sort's "loop"
		template<class LoopTuple, std::size_t TupleSize, std::size_t I, std::size_t J>
		struct tuple_selection_sort_impl {
			// This is done until we have compared every element in the type list
			using tuple_type = std::conditional_t<
				Comparator<std::tuple_element_t<I, LoopTuple>, std::tuple_element_t<J, LoopTuple>>::value,	// Swap predicate
				typename tuple_element_swap<LoopTuple, I, J>::type,											// true: swap(I, J)
				LoopTuple																					// false: do nothing
			>;

			using type = typename tuple_selection_sort_impl< // Recurse until J == TupleSize
				tuple_type, TupleSize, I, J + 1 // Using the modified tuple
			>::type;
		};

		template<class LoopTuple, std::size_t TupleSize, std::size_t I>
		struct tuple_selection_sort_impl<LoopTuple, TupleSize, I, TupleSize> {
			// Once J == TupleSize, we increment I and start J at I + 1 and recurse
			using type = typename tuple_selection_sort_impl<
				LoopTuple, TupleSize, I + 1, I + 2
			>::type;
		};

		template<class LoopTuple, std::size_t TupleSize, std::size_t J>
		struct tuple_selection_sort_impl<LoopTuple, TupleSize, TupleSize, J> {
			// Once I == TupleSize, we know that every element has been compared
			using type = LoopTuple;
		};

	public:
		using type = typename tuple_selection_sort_impl<Tuple, std::tuple_size_v<Tuple>, 0, 1>::type;
	};
	template <template <class, class> class Comparator, class Tuple>
	using tuple_selection_sort_t = typename tuple_selection_sort<Comparator, Tuple>::type;
}
