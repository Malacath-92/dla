#pragma once

#if not defined DLA_FMT_FORMAT and defined __has_include
#if __has_include(<fmt/format.h>)
#define DLA_FMT_FORMAT
#endif
#endif

#ifdef DLA_FMT_FORMAT
#include <dla/units.h>

#include <fmt/format.h>

template<class Tag>
struct fmt::formatter<dla::base_unit<Tag>>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx);
    template<typename FormatContext>
    constexpr auto format(const dla::base_unit<Tag>& val, FormatContext& ctx) const;
};

template<class... Tags>
struct fmt::formatter<dla::comp_unit<Tags...>>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx);
    template<typename FormatContext>
    constexpr auto format(const dla::comp_unit<Tags...>& val, FormatContext& ctx) const;
};

template<class T, std::size_t N>
struct fmt::formatter<dla::vec<T, N>>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx);
    template<typename FormatContext>
    constexpr auto format(const dla::vec<T, N>& val, FormatContext& ctx) const;
};

template<class T, std::size_t N, std::size_t M>
struct fmt::formatter<dla::mat<T, N, M>>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx);
    template<typename FormatContext>
    constexpr auto format(const dla::mat<T, N, M>& val, FormatContext& ctx) const;
};

#include "fmt_format.inl"
#endif
