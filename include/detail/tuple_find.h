#include <tuple>

namespace dla::detail {
	inline constexpr std::size_t tuple_find_npos = static_cast<size_t>(-1);
	template<class T, class Tuple>
	struct tuple_find;
	template<class T>
	struct tuple_find<T, std::tuple<>> {
		static constexpr std::size_t value = tuple_find_npos;
	};
	template<class T, class... Types>
	struct tuple_find<T, std::tuple<T, Types...>> {
		static constexpr std::size_t value = 0;
	};
	template<class T, class U, class... Types>
	struct tuple_find<T, std::tuple<U, Types...>> {
	private:
		static constexpr std::size_t next = tuple_find<T, std::tuple<Types...>>::value;

	public:
#	ifdef _MSVC_LANG
#	pragma warning(disable : 4307) // MSVC emits integer overflow on this line
		static constexpr std::size_t value = (next == tuple_find_npos) ? (next) : (1 + next);
#	pragma warning(default : 4307)
#	else
		static constexpr std::size_t value = (next == tuple_find_npos) ? (next) : (1 + next);
#	endif
	};
	template<class T, class Tuple>
	inline constexpr std::size_t tuple_find_v = tuple_find<T, Tuple>::value;
}