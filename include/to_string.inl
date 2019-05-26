#pragma once

#include "detail/detail.h"
#include "detail/tuple_sort.h"
#include "to_string.h"

namespace dla {
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	struct base_unit;
	template<class... Units>
	struct comp_unit;

    template<class T, std::size_t N>
    struct vec;
    template<class T, std::size_t N, std::size_t M>
    struct mat;

    // TODO: Make a clearer implementation for to_string
    template<class T>
    struct to_string_impl {
		template<class T>
		struct unit_to_string;
	    template<class Tag, std::intmax_t Num, std::intmax_t Den>
        struct unit_to_string<base_unit<Tag, Num, Den>> {
            static std::string call() {
                return " " + std::string(Tag::symbol)
                    + "^(" + (Num * Den < 0 ? "-" : "")
                    + std::to_string(std::abs(Num)) + "/" + std::to_string(std::abs(Den)) + ")";
            }
        };
	    template<class Tag, std::intmax_t Num>
        struct unit_to_string<base_unit<Tag, Num, 1>> {
            static std::string call() {
                return " " + std::string(Tag::symbol) + "^" + (Num < 0 ? "-" : "") + std::to_string(std::abs(Num));
            }
        };
	    template<class Tag, std::intmax_t Den>
        struct unit_to_string<base_unit<Tag, 1, Den>> {
            static std::string call() {
                return " " + std::string(Tag::symbol)
                    + "^(" + (Den < 0 ? "-" : "")
                    + "1/" + std::to_string(std::abs(Den)) + ")";
            }
        };
	    template<class Tag>
        struct unit_to_string<base_unit<Tag, 1, 1>> {
            static std::string call() {
                return " " + std::string(Tag::symbol);
            }
        };
        static auto call(const T& val) = delete;
    };
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
    struct to_string_impl<base_unit<Tag, Num, Den>> {
        static auto call(const base_unit<Tag, Num, Den>& val) {
            return std::to_string(float(val)) + to_string_impl<int>::unit_to_string<base_unit<Tag, Num, Den>>::call();
        }
    };
	template<class... Units>
    struct to_string_impl<comp_unit<Units...>> {
	private:
		template<class lUnit, class rUnit>
		struct sorting_predicate {
			static constexpr bool value = lUnit::ratio::num * rUnit::ratio::den < rUnit::ratio::num * lUnit::ratio::den;
		};

        using sortedUnits = detail::tuple_selection_sort_t<sorting_predicate, std::tuple<Units...>>;
    public:
        static auto call(const comp_unit<Units...>& val) {
			return std::to_string(float(val))
				+ std::apply([](auto... v) { return (to_string_impl<int>::unit_to_string<decltype(v)>::call() + ...); }, sortedUnits{});
        }
    };

    template<class T, std::size_t N>
    struct to_string_impl<vec<T, N>> {
        static auto call(const vec<T, N>&) {
            return "vec";
        }
    };
    template<class T, std::size_t N, std::size_t M>
    struct to_string_impl<mat<T, N, M>> {
        static auto call(const mat<T, N, M>&) {
            return "mat";
        }
    };

    template<class CharT, class Traits, class T>
    struct stream_insert_impl {
        static decltype(auto) call(const T& val) = delete;
    };
	template<class CharT, class Traits, class Tag, std::intmax_t Num, std::intmax_t Den>
    struct stream_insert_impl<CharT, Traits, base_unit<Tag, Num, Den>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const base_unit<Tag, Num, Den>& val) {
            return stream << to_string(val);
        }
    };
	template<class CharT, class Traits, class... Units>
    struct stream_insert_impl<CharT, Traits, comp_unit<Units...>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const comp_unit<Units...>& val) {
            return stream << to_string(val);
        }
    };

    template<class CharT, class Traits, class T, std::size_t N>
    struct stream_insert_impl<CharT, Traits, vec<T, N>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const vec<T, N>& val) {
            return stream << to_string(val);
        }
    };
    template<class CharT, class Traits, class T, std::size_t N, std::size_t M>
    struct stream_insert_impl<CharT, Traits, mat<T, N, M>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const mat<T, N, M>& val) {
            return stream << to_string(val);
        }
    };

    
    template<class T>
    std::string to_string(const T& val) {
        return to_string_impl<T>::call(val);
    }

    template<class CharT, class Traits, class T>
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& stream, const T& val) {
        return stream_insert_impl<CharT, Traits, T>::call(stream, val);
    }
}
