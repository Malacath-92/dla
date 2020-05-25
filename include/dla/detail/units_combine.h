#pragma once

#include <cstdint>
#include <type_traits>
#include <ratio>

#include "string.h"
#include "tuple_sort.h"
#include "tuple_find.h"

namespace dla {
	template<class Name, std::intmax_t Num, std::intmax_t Den>
	struct unit_tag;
	template<class Tag>
	struct base_unit;
	template<class... Tags>
	struct comp_unit;
}

namespace dla::detail {
	template<class... Tags>
	struct sorted_comp_unit {
	private:
		template<class lTag, class rTag>
		struct sorting_predicate {
			using lName = typename lTag::name_t;
			using rName = typename rTag::name_t;
			static constexpr auto comp = compare(lName::id, rName::id);
			static constexpr bool value = comp < 0;
			static_assert(comp != 0, "Duplicate tag found in units!");
		};

		template<class IndexSequence>
		struct sort_into_comp_unit;
		template<std::size_t... Is>
		struct sort_into_comp_unit<std::index_sequence<Is...>> {
			using sorted_tuple = tuple_selection_sort_t<sorting_predicate, std::tuple<Tags...>>;
			using type = comp_unit<std::tuple_element_t<Is, sorted_tuple>...>;
		};

	public:
		using type = typename sort_into_comp_unit<std::make_index_sequence<sizeof...(Tags)>>::type;
	};
	template<>
	struct sorted_comp_unit<> {
		using type = float;
	};
	template<class... Tags>
	using sorted_comp_unit_t = typename sorted_comp_unit<Tags...>::type;

	template<class T>
	struct inverse;
	template<class Name, std::intmax_t Num, std::intmax_t Den>
	struct inverse<unit_tag<Name, Num, Den>> {
		using type = unit_tag<Name, -Num, Den>;
	};
	template<class Tag>
	struct inverse<base_unit<Tag>> {
		using type = base_unit<typename inverse<Tag>::type>;
	};
	template<class... Tags>
	struct inverse<comp_unit<Tags...>> {
		using type = comp_unit<typename inverse<Tags>::type...>;
	};
	template<class T>
	using inverse_t = typename inverse<T>::type;

	template<class T, class U>
	struct multiply;
	template<class Name, std::intmax_t lNum, std::intmax_t lDen, std::intmax_t rNum, std::intmax_t rDen>
	struct multiply<base_unit<unit_tag<Name, lNum, lDen>>, base_unit<unit_tag<Name, rNum, rDen>>> {
	private:
		using result_ratio = std::ratio_add<std::ratio<lNum, lDen>, std::ratio<rNum, rDen>>;

	public:
		using type = std::conditional_t<result_ratio::num != 0,
			base_unit<unit_tag<Name, result_ratio::num, result_ratio::den>>,
			float
		>;
	};
	template<class lName, std::intmax_t lNum, std::intmax_t lDen, class rName, std::intmax_t rNum, std::intmax_t rDen>
	struct multiply<base_unit<unit_tag<lName, lNum, lDen>>, base_unit<unit_tag<rName, rNum, rDen>>> {
		using type = sorted_comp_unit_t<unit_tag<lName, lNum, lDen>, unit_tag<rName, rNum, rDen>>;
	};
	template<class Tag, class... Tags>
	struct multiply<base_unit<Tag>, comp_unit<Tags...>> {
	private:
		using lUnit = base_unit<Tag>;
		using rUnit = comp_unit<Tags...>;

		static constexpr std::size_t tagIndex = tuple_find_v<typename Tag::name_t, std::tuple<typename Tags::name_t...>>;

		template<class T, class Ts, std::size_t index>
		struct indexed_multiply;
		template<class T, class... Ts>
		struct indexed_multiply<T, std::tuple<Ts...>, tuple_find_npos> {
			using type = sorted_comp_unit_t<T, Ts...>;
		};
		template<class T, class... Ts, std::size_t index>
		struct indexed_multiply<T, std::tuple<Ts...>, index> {
		private:
			using before_multiplied = base_unit<std::tuple_element_t<index, std::tuple<Ts...>>>;
			using multiplied = typename multiply<before_multiplied, base_unit<T>>::type;

			template<class U>
			struct tag {
				using type = std::tuple<>;
			};
			template<class U>
			struct tag<base_unit<U>> {
				using type = std::tuple<U>;
			};

			template<class IndexSequence>
			struct replace_index_and_skip_float;
			template<std::size_t... Is>
			struct replace_index_and_skip_float<std::index_sequence<Is...>> {
				template<class...Us>
				using tuple_cat_t = decltype(std::tuple_cat(std::declval<Us>()...));

				using type = tuple_cat_t<
					std::conditional_t<
						Is == index,
						typename tag<multiplied>::type,
						std::tuple<Ts>
					>...
				>;
			};

			template<class Tuple>
			struct unpack_into_comp_unit;
			template<class... Us>
			struct unpack_into_comp_unit<std::tuple<Us...>> {
				using type = sorted_comp_unit_t<Us...>;
			};

			using result_tuple = typename replace_index_and_skip_float<std::make_index_sequence<sizeof...(Tags)>>::type;

		public:
			using type = typename unpack_into_comp_unit<result_tuple>::type;
		};

	public:
		using type = typename indexed_multiply<Tag, std::tuple<Tags...>, tagIndex>::type;
	};
	template<class Tag, class... Tags>
	struct multiply<comp_unit<Tags...>, base_unit<Tag>> {
	private:
		using lUnit = comp_unit<Tags...>;
		using rUnit = base_unit<Tag>;

	public:
		using type = typename multiply<rUnit, lUnit>::type;
	};
	template<class... lTags, class... rTags>
	struct multiply<comp_unit<lTags...>, comp_unit<rTags...>> {
	private:
		using lUnit = comp_unit<lTags...>;

		template<class lUnitToMult, class rUnitToMult, class... rUnits>
		struct iterative_multiply {
			using type = typename iterative_multiply<typename multiply<lUnitToMult, rUnitToMult>::type, rUnits...>::type;
		};
		template<class lUnitToMult, class rUnitToMult>
		struct iterative_multiply<lUnitToMult, rUnitToMult> {
			using type = typename multiply<lUnitToMult, rUnitToMult>::type;
		};

	public:
		using type = typename iterative_multiply<lUnit, base_unit<rTags>...>::type;
	};

	template<class T, std::intmax_t pNum, std::intmax_t pDen>
	struct power {
		using type = T;
	};
	template<class Name, std::intmax_t Num, std::intmax_t Den, std::intmax_t pNum, std::intmax_t pDen>
	struct power<unit_tag<Name, Num, Den>, pNum, pDen> {
	private:
		using result_ratio = std::ratio_multiply<std::ratio<Num, Den>, std::ratio<pNum, pDen>>;
	public:
		using type = unit_tag<Name, result_ratio::num, result_ratio::den>;
	};
	template<class Tag, std::intmax_t pNum, std::intmax_t pDen>
	struct power<base_unit<Tag>, pNum, pDen> {
		using type = base_unit<typename power<Tag, pNum, pDen>::type>;
	};
	template<class... Tags, std::intmax_t pNum, std::intmax_t pDen>
	struct power<comp_unit<Tags...>, pNum, pDen> {
		using type = comp_unit<typename power<Tags, pNum, pDen>::type...>;
	};

	template<class T, class U>
	using multiply_t = typename multiply<T, U>::type;
	template<class T, class U>
	using divide_t = multiply_t<T, inverse_t<U>>;
	template<class T, std::intmax_t pNum, std::intmax_t pDen>
	using power_t = typename power<T, pNum, pDen>::type;
}
