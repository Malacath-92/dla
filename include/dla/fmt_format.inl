#pragma once

#include "fmt_format.h"
#include "to_string.h"

template<class Tag>
template<typename ParseContext>
constexpr auto fmt::formatter<dla::base_unit<Tag>>::parse(ParseContext& ctx)
{
    return ctx.begin();
}

template<class Tag>
template<typename FormatContext>
constexpr auto fmt::formatter<dla::base_unit<Tag>>::format(const dla::base_unit<Tag>& val, FormatContext& ctx) const
{
    return fmt::format_to(ctx.out(), "{}", dla::to_string(val));
}

template<class... Tags>
template<typename ParseContext>
constexpr auto fmt::formatter<dla::comp_unit<Tags...>>::parse(ParseContext& ctx)
{
    return ctx.begin();
}

template<class... Tags>
template<typename FormatContext>
constexpr auto fmt::formatter<dla::comp_unit<Tags...>>::format(const dla::comp_unit<Tags...>& val, FormatContext& ctx) const
{
    return fmt::format_to(ctx.out(), "{}", dla::to_string(val));
}

template<class T, std::size_t N>
template<typename ParseContext>
constexpr auto fmt::formatter<dla::vec<T, N>>::parse(ParseContext& ctx)
{
    return ctx.begin();
}

template<class T, std::size_t N>
template<typename FormatContext>
constexpr auto fmt::formatter<dla::vec<T, N>>::format(const dla::vec<T, N>& val, FormatContext& ctx) const
{
    return fmt::format_to(ctx.out(), "{}", dla::to_string(val));
}

template<class T, std::size_t N, std::size_t M>
template<typename ParseContext>
constexpr auto fmt::formatter<dla::mat<T, N, M>>::parse(ParseContext& ctx)
{
    return ctx.begin();
}

template<class T, std::size_t N, std::size_t M>
template<typename FormatContext>
constexpr auto fmt::formatter<dla::mat<T, N, M>>::format(const dla::mat<T, N, M>& val, FormatContext& ctx) const
{
    return fmt::format_to(ctx.out(), "{}", dla::to_string(val));
}
