#pragma once

#include "detail/tuple_sort.h"
#include "detail/static_string.h"
#include "to_string.h"

#include <charconv>
#include <numeric>

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

    constexpr std::size_t exact_abs_int_len(std::intmax_t value)
    {
        if (value == 0)
        {
            return 1;
        }
        if (value < 0)
        {
            value = -value;
        }
        std::size_t count = 0;
        while (value > 0)
        {
            count++;
            value /= 10;
        }
        return count;
    }

    template<std::intmax_t Num>
    struct int_to_string
    {
        inline static constexpr auto NumAbs{
            Num < 0 ? -Num : Num
        };
        inline static constexpr static_string value{
            []() {
                constexpr auto buff_len{ exact_abs_int_len(NumAbs) };
                char buff[buff_len + 1]{};

                if constexpr (Num == 0)
                {
                    buff[0] = '0';
                }
                else
                {
                    auto temp{ NumAbs };
                    auto idx{ buff_len };
                    while (temp > 0)
                    {
                        buff[--idx] = static_cast<char>('0' + (temp % 10));
                        temp /= 10;
                    }
                }

                return static_string{ buff };
            }()
        };
    };
    
    template<std::intmax_t Num, std::intmax_t Den, bool Neg>
    struct ratio_to_string_impl;
    template<std::intmax_t Num, std::intmax_t Den>
    struct ratio_to_string_impl<Num, Den, true> {
        inline static constexpr static_string value{
            "-"
                + int_to_string<Num>::value
                + "/"
                + int_to_string<Den>::value
        };
    };
    template<std::intmax_t Num>
    struct ratio_to_string_impl<Num, 1, true> {
        inline static constexpr static_string value{
            "-" + int_to_string<Num>::value
        };
    };
    template<std::intmax_t Num, std::intmax_t Den>
    struct ratio_to_string_impl<Num, Den, false> {
        inline static constexpr static_string value{
            int_to_string<Num>::value
                + "/"
                + int_to_string<Den>::value
        };
    };
    template<std::intmax_t Num>
    struct ratio_to_string_impl<Num, 1, false> {
        inline static constexpr static_string value{
            int_to_string<Num>::value
        };
    };
    template<std::intmax_t Num, std::intmax_t Den>
    struct ratio_to_string
        : public ratio_to_string_impl<Num, Den, Num * Den < 0> {
    };

    template<class T>
    struct tag_to_string;
    template<class Name, std::intmax_t Num, std::intmax_t Den>
    struct tag_to_string<unit_tag<Name, Num, Den>> {
        inline static constexpr static_string value{
            static_string{ Name::symbol }
                + "^("
                + ratio_to_string<Num, Den>::value
                + ")"
        };
    };
    template<class Name, std::intmax_t Num>
    struct tag_to_string<unit_tag<Name, Num, 1>> {
        inline static constexpr static_string value{
            static_string{ Name::symbol }
                + "^"
                + ratio_to_string<Num, 1>::value
        };
    };
    template<class Name>
    struct tag_to_string<unit_tag<Name, 1, 1>> {
        inline static constexpr static_string value{
            Name::symbol
        };
    };

    template<class T>
    struct unit_to_string;
    template<class Tag>
    struct unit_to_string<base_unit<Tag>>
    {
        inline static constexpr static_string value{
            tag_to_string<Tag>::value
        };
    };
    template<class... Tags>
    struct unit_to_string<comp_unit<Tags...>>
    {
      private:
        template<class lUnit, class rUnit>
        struct sorting_predicate
        {
            static constexpr bool value = lUnit::ratio_t::num * rUnit::ratio_t::den < rUnit::ratio_t::num * lUnit::ratio_t::den;
        };

        using sortedTags = detail::tuple_selection_sort_t<sorting_predicate, std::tuple<Tags...>>;

      public:
        inline static constexpr static_string value{
            std::apply([](auto... v)
                       { return ((' ' + tag_to_string<decltype(v)>::value) + ...); },
                       sortedTags{})
                .template substr<1>()
        };
    };
    template<>
    struct unit_to_string<comp_unit<>>
    {
        inline static constexpr static_string value{ "" };
    };

    template<class T>
    struct to_string_impl {
        static auto call(const T& val) {
            return std::to_string(val);
        }
    };
	template<class Tag>
    struct to_string_impl<base_unit<Tag>> {
        static auto call(const base_unit<Tag>& val) {
            return std::to_string(float(val)) + ' ' + tag_to_string<Tag>::value;
        }
    };
	template<class... Tags>
    struct to_string_impl<comp_unit<Tags...>> {
        static auto call(const comp_unit<Tags...>& val) {
            return std::to_string(float(val)) + ' ' + unit_to_string<comp_unit<Tags...>>::value;
        }
    };

    template<class T, std::size_t N>
    struct to_string_impl<vec<T, N>> {
        static auto call(const vec<T, N>& val) {
            if constexpr (N == 1) {
                return to_string(val.x);
            }
            else {
				std::string list = to_string(val.x);
                for (std::size_t i = 1; i < N; i++) {
                    list += ", " + to_string(val[i]);
                }
                return "{ " + list + " }";
            }
        }
    };
    template<class T, std::size_t N, std::size_t M>
    struct to_string_impl<mat<T, N, M>> {
        static auto call(const mat<T, N, M>& val) {
			if constexpr(N == 1 && M == 1) {
				return to_string(val.x.x);
			}
			else {
				std::string list = to_string(val.x);
				for(std::size_t i = 1; i < N; i++) {
					list += ", " + to_string(val[i]);
				}
				return "{ " + list + " }";
			}
        }
    };

    template<class CharT, class Traits, class T>
    struct stream_insert_impl {
        static decltype(auto) call(const T& val) = delete;
    };
	template<class CharT, class Traits, class Tag>
    struct stream_insert_impl<CharT, Traits, base_unit<Tag>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const base_unit<Tag>& val) {
            return stream << to_string(val);
        }
    };
	template<class CharT, class Traits, class... Tags>
    struct stream_insert_impl<CharT, Traits, comp_unit<Tags...>> {
        static decltype(auto) call(std::basic_ostream<CharT, Traits>& stream, const comp_unit<Tags...>& val) {
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
