#pragma once

#include <cstdint>
#include <type_traits>
#include <ratio>
#include <string>
#include <algorithm>

#include "tuple_sort.h"
#include "tuple_index.h"

#ifdef _MSVC_LANG
#define declare_unreachable() __assume(false)
#else
#define declare_unreachable() __builtin_unreachable()
#endif

namespace unit {
	template<class Unit, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;

	namespace detail {
		template<class charT>
		constexpr size_t strlen(const charT* str) {
			std::size_t size = 0;
			while(*str) {
				str++;
				size++;
			}
			return size + 1;
		}
		template<class charT, class traits = std::char_traits<charT>>
		constexpr int compare(const charT* lhs, std::size_t lhsLen,
							  const charT* rhs, std::size_t rhsLen) {
		#ifdef _MSVC_LANG
			if(lhs != rhs) {
		#else
			{ // gcc and clang do not allow comparison of charT* in a constant expression
		#endif
				const int result = traits::compare(lhs, rhs, std::min(lhsLen, rhsLen));
				if(result != 0)
					return result;
			}
			if(lhsLen == rhsLen) {
				return 0;
			}
			return lhsLen < rhsLen ? -1 : 1;
		}
		template<class charT, class traits = std::char_traits<charT>>
		constexpr int compare(const charT* lhs, const charT* rhs) {
			std::size_t lhsLen = strlen(lhs);
			std::size_t rhsLen = strlen(rhs);
			return compare(lhs, lhsLen, rhs, rhsLen);
		}

		template<class U>
		struct is_base_unit : std::false_type {};
		template<class Tag, std::intmax_t Num, std::intmax_t Den>
		struct is_base_unit<base_unit<Tag, Num, Den>> : std::true_type {};
		template<class U>
		inline constexpr bool is_base_unit_v = is_base_unit<U>::value;

		template<class... Units>
		struct sorted_comp_unit {
		private:
			template<class lTag, class rTag>
			struct sorting_predicate {
				static constexpr auto comp = compare(lTag::tag::id, rTag::tag::id);
				static constexpr bool value = comp < 0;
				static_assert(comp != 0, "Duplicate tag found in units!");
			};

			template<class IndexSequence>
			struct sort_into_comp_unit;
			template<std::size_t... Is>
			struct sort_into_comp_unit<std::index_sequence<Is...>> {
				using sorted_tuple = tuple_selection_sort_t<sorting_predicate, std::tuple<Units...>>;
				using type = comp_unit<std::tuple_element_t<Is, sorted_tuple>...>;
			};

		public:
			using type = typename sort_into_comp_unit<std::make_index_sequence<sizeof...(Units)>>::type;
		};
		template<>
		struct sorted_comp_unit<> {
			using type = float;
		};
		template<class... Units>
		using sorted_comp_unit_t = typename sorted_comp_unit<Units...>::type;

		template<class T>
		struct inverse;
		template<class Tag, std::intmax_t Num, std::intmax_t Den>
		struct inverse<base_unit<Tag, Num, Den>> {
			using type = base_unit<Tag, -Num, Den>;
		};
		template<class... Units>
		struct inverse<comp_unit<Units...>> {
			using type = comp_unit<typename inverse<Units>::type...>;
		};
		template<class T>
		using inverse_t = typename inverse<T>::type;

		template<class... T>
		struct always_false : std::false_type {};
		template<class... T>
		inline constexpr bool always_false_v = always_false<T...>::value;

		template<class T, class U>
		struct multiply;
		template<class Tag, std::intmax_t lNum, std::intmax_t lDen, std::intmax_t rNum, std::intmax_t rDen>
		struct multiply<base_unit<Tag, lNum, lDen>, base_unit<Tag, rNum, rDen>> {
		private:
			using result_ratio = std::ratio_add<std::ratio<lNum, lDen>, std::ratio<rNum, rDen>>;

		public:
			using type = std::conditional_t<result_ratio::num != 0,
				base_unit<Tag, result_ratio::num, result_ratio::den>,
				float
			>;
		};
		template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class rTag, std::intmax_t rNum, std::intmax_t rDen>
		struct multiply<base_unit<lTag, lNum, lDen>, base_unit<rTag, rNum, rDen>> {
		private:
			using lUnit = base_unit<lTag, lNum, lDen>;
			using rUnit = base_unit<rTag, rNum, rDen>;

		public:
			using type = sorted_comp_unit_t<lUnit, rUnit>;
		};
		template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class... Units>
		struct multiply<base_unit<lTag, lNum, lDen>, comp_unit<Units...>> {
		private:
			using lUnit = base_unit<lTag, lNum, lDen>;
			using rUnit = comp_unit<Units...>;

			static constexpr std::size_t tagIndex = tuple_find_v<typename lUnit::tag, std::tuple<typename Units::tag...>>;

			template<class T, class Tuple, std::size_t index>
			struct indexed_multiply;
			template<class T, class... Ts>
			struct indexed_multiply<T, std::tuple<Ts...>, tuple_index_npos> {
				using type = sorted_comp_unit_t<T, Ts...>;
			};
			template<class T, class... Ts, std::size_t index>
			struct indexed_multiply<T, std::tuple<Ts...>, index> {
			private:
				using before_multiplied = std::tuple_element_t<index, std::tuple<Ts...>>;
				using multiplied = typename multiply<before_multiplied, T>::type;

				template<class IndexSequence>
				struct replace_index_and_skip_float;
				template<std::size_t... Is>
				struct replace_index_and_skip_float<std::index_sequence<Is...>> {
					template<class...Us>
					using tuple_cat_t = decltype(std::tuple_cat(std::declval<Us>()...));
					using type = tuple_cat_t<
						std::conditional_t<
						Is == index,
						std::conditional_t<std::is_same_v<float, multiplied>,
						std::tuple<>,
						std::tuple<multiplied>
						>,
						std::tuple<Units>
						>...
					>;
				};

				template<class Tuple>
				struct unpack_into_comp_unit;
				template<class... Us>
				struct unpack_into_comp_unit<std::tuple<Us...>> {
					using type = sorted_comp_unit_t<Us...>;
				};

				using result_tuple = typename replace_index_and_skip_float<std::make_index_sequence<sizeof...(Units)>>::type;

			public:
				using type = typename unpack_into_comp_unit<result_tuple>::type;
			};

		public:
			using type = typename indexed_multiply<lUnit, std::tuple<Units...>, tagIndex>::type;
		};
		template<class rTag, std::intmax_t rNum, std::intmax_t rDen, class... Units>
		struct multiply<comp_unit<Units...>, base_unit<rTag, rNum, rDen>> {
		private:
			using lUnit = comp_unit<Units...>;
			using rUnit = base_unit<rTag, rNum, rDen>;

		public:
			using type = typename multiply<rUnit, lUnit>::type;
		};
		template<class... lUnits, class... rUnits>
		struct multiply<comp_unit<lUnits...>, comp_unit<rUnits...>> {
		private:
			using lUnit = comp_unit<lUnits...>;
			using rUnit = comp_unit<rUnits...>;

			template<class lhs, class rUnitToMult, class... rUnitsLeft>
			struct iterative_multiply {
				using type = typename iterative_multiply<typename multiply<lhs, rUnitToMult>::type, rUnitsLeft...>::type;
			};
			template<class lhs, class rUnitToMult>
			struct iterative_multiply<lhs, rUnitToMult> {
				using type = typename multiply<lhs, rUnitToMult>::type;
			};

		public:
			using type = typename iterative_multiply<lUnit, rUnits...>::type;
		};
		template<class T, std::intmax_t pNum, std::intmax_t pDen>
		struct power {
			static_assert(always_false_v<T>, "T needs to be base_unit or comp_unit");
		};
		template<class Tag, std::intmax_t Num, std::intmax_t Den, std::intmax_t pNum, std::intmax_t pDen>
		struct power<base_unit<Tag, Num, Den>, pNum, pDen> {
		private:
			using result_ratio = std::ratio_multiply<std::ratio<Num, Den>, std::ratio<pNum, pDen>>;
		public:
			using type = base_unit<Tag, result_ratio::num, result_ratio::den>;
		};
		template<class... Units, std::intmax_t pNum, std::intmax_t pDen>
		struct power<comp_unit<Units...>, pNum, pDen> {
			using type = comp_unit<typename power<Units, pNum, pDen>::type...>;
		};

		template<class T, class U>
		using multiply_t = typename multiply<T, U>::type;
		template<class T, class U>
		using divide_t = multiply_t<T, inverse_t<U>>;
		template<class T, std::intmax_t pNum, std::intmax_t pDen>
		using power_t = typename power<T, pNum, pDen>::type;

		// TODO: Members should not be zero-initialized, not doing this causes some constexpr problems
		template<class T, std::size_t N>
		struct vec_elements {
	        static_assert(N > 0 && N <= 5, "Vectors only supported for sizes 1, 2, 3 and 4!");
		};
		template<class T>
		struct vec_elements<T, 1> {
			constexpr vec_elements() = default;
			constexpr vec_elements(const vec_elements&) = default;
			constexpr vec_elements(vec_elements&&) = default;
			constexpr vec_elements& operator=(const vec_elements&) = default;
			constexpr vec_elements& operator=(vec_elements&&) = default;

			template<class U>
			constexpr explicit vec_elements(const vec_elements<U, 1>& val) :
				x(static_cast<T>(val.x)) {}
			
			constexpr explicit vec_elements(const T& pX) :
				x(pX) {}
			template<class U>
			constexpr explicit vec_elements(const U& val) : 
				x(static_cast<T>(val)) {}
			constexpr explicit vec_elements(T&& pX) :
				x(std::forward<decltype(pX)>(pX)) {}

			T x{};
		};
		template<class T>
		struct vec_elements<T, 2> {
			constexpr vec_elements() = default;
			constexpr vec_elements(const vec_elements&) = default;
			constexpr vec_elements(vec_elements&&) = default;
			constexpr vec_elements& operator=(const vec_elements&) = default;
			constexpr vec_elements& operator=(vec_elements&&) = default;

			template<class U>
			constexpr explicit vec_elements(const vec_elements<U, 2>& val) :
				x(static_cast<T>(val.x)),
				y(static_cast<T>(val.y)) {}
			
			template<class U>
			constexpr explicit vec_elements(const U& val) :
				x(static_cast<T>(val)),
				y(static_cast<T>(val)) {}
			constexpr vec_elements(const T& pX, const T& pY) :
				x(pX),
				y(pY) {}
			template<class U>
			constexpr vec_elements(const U& pX, const U& pY) :
				x(static_cast<T>(pX)),
				y(static_cast<T>(pY)) {}
			constexpr vec_elements(T&& pX, T&& pY) :
				x(std::forward<decltype(pX)>(pX)),
				y(std::forward<decltype(pY)>(pY)) {}
			
			T x{}, y{};
		};
		template<class T>
		struct vec_elements<T, 3> {
			constexpr vec_elements() = default;
			constexpr vec_elements(const vec_elements&) = default;
			constexpr vec_elements(vec_elements&&) = default;
			constexpr vec_elements& operator=(const vec_elements&) = default;
			constexpr vec_elements& operator=(vec_elements&&) = default;

			template<class U>
			constexpr explicit vec_elements(const vec_elements<U, 3>& val) :
				x(static_cast<T>(val.x)),
				y(static_cast<T>(val.y)),
				z(static_cast<T>(val.z)) {}

			template<class U>
			constexpr explicit vec_elements(const U& val) :
				x(static_cast<T>(val)),
				y(static_cast<T>(val)),
				z(static_cast<T>(val)) {}
			constexpr vec_elements(const T& pX, const T& pY, const T& pZ) :
				x(pX),
				y(pY),
				z(pZ) {}
			template<class U>
			constexpr vec_elements(const U& pX, const U& pY, const U& pZ) : 
				x(static_cast<T>(pX)),
				y(static_cast<T>(pY)),
				z(static_cast<T>(pZ)) {}
			constexpr vec_elements(T&& pX, T&& pY, T&& pZ) :
				x(std::forward<decltype(pX)>(pX)),
				y(std::forward<decltype(pY)>(pY)),
				z(std::forward<decltype(pZ)>(pZ)) {}
			
			T x{}, y{}, z{};
		};
		template<class T>
		struct vec_elements<T, 4> {
			constexpr vec_elements() = default;
			constexpr vec_elements(const vec_elements&) = default;
			constexpr vec_elements(vec_elements&&) = default;
			constexpr vec_elements& operator=(const vec_elements&) = default;
			constexpr vec_elements& operator=(vec_elements&&) = default;

			template<class U>
			constexpr explicit vec_elements(const vec_elements<U, 4>& val) :
				x(static_cast<T>(val.x)),
				y(static_cast<T>(val.y)),
				z(static_cast<T>(val.z)),
				w(static_cast<T>(val.w)) {}

			template<class U>
			constexpr explicit vec_elements(const U& val) :
				x(static_cast<T>(val)),
				y(static_cast<T>(val)),
				z(static_cast<T>(val)),
				w(static_cast<T>(val)) {}
			constexpr vec_elements(const T& pX, const T& pY, const T& pZ, const T& pW) :
				x(pX),
				y(pY),
				z(pZ), 
				w(pW) {}
			template<class U>
			constexpr vec_elements(const U& pX, const U& pY, const U& pZ, const U& pW) :
				x(static_cast<T>(pX)),
				y(static_cast<T>(pY)),
				z(static_cast<T>(pZ)), 
				w(static_cast<T>(pW)) {}
			constexpr vec_elements(T&& pX, T&& pY, T&& pZ, T&& pW) :
				x(std::forward<decltype(pX)>(pX)),
				y(std::forward<decltype(pY)>(pY)),
				z(std::forward<decltype(pZ)>(pZ)),
				w(std::forward<decltype(pZ)>(pW)) {}
			
			T x{}, y{}, z{}, w{};
		};

		template<class T, std::size_t N>
		class vec_iterator {
		public:
			constexpr vec_iterator(T& vec, std::size_t startIdx) noexcept : mVec(vec), mIdx(startIdx) {}

			constexpr vec_iterator(const vec_iterator&) noexcept = default;
			constexpr vec_iterator& operator=(const vec_iterator&) noexcept = default;

			// TODO: Conditional noexcept
			constexpr decltype(auto) operator*() const noexcept {
				return mVec[mIdx];
			}
			constexpr decltype(auto) operator*() noexcept {
				return mVec[mIdx];
			}

			constexpr decltype(auto) operator++() noexcept {
				mIdx++;
				return *this;
			}
			[[nodiscard]] constexpr auto operator++(int) noexcept {
				auto prev = *this;
				mIdx++;
				return prev;
			}

			constexpr decltype(auto) operator--() noexcept {
				mIdx--;
				return *this;
			}
			[[nodiscard]] constexpr auto operator--(int) noexcept {
				auto prev = *this;
				mIdx--;
				return prev;
			}
		
			constexpr auto operator+(int rhs) const noexcept {
				auto res{ *this };
				res.mIdx += rhs;
				return res;
			}
			constexpr auto operator-(int rhs) const noexcept {
				return *this + (-rhs);
			}
		
			constexpr decltype(auto) operator+=(int rhs) noexcept {
				*this = *this + rhs;
				return *this;
			}
			constexpr decltype(auto) operator-=(int rhs) noexcept {
				return *this += (-rhs);
			}

			constexpr auto operator==(const vec_iterator& rhs) noexcept {
				return &mVec == &rhs.mVec && mIdx == rhs.mIdx;
			}
			constexpr auto operator!=(const vec_iterator& rhs) noexcept {
				return &mVec != &rhs.mVec || mIdx != rhs.mIdx;
			}

		private:
			T& mVec;
			std::size_t mIdx;
		};
	}
}
