#pragma once

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

    // TODO: Make a real implementation for to_string
    template<class T>
    struct to_string_impl {
        static auto call(const T& val) = delete;
    };
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
    struct to_string_impl<base_unit<Tag, Num, Den>> {
        static auto call(const base_unit<Tag, Num, Den>&) {
            return "base_unit";
        }
    };
	template<class... Units>
    struct to_string_impl<comp_unit<Units...>> {
        static auto call(const comp_unit<Units...>&) {
            return "comp_unit";
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
