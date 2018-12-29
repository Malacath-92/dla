#pragma once

#include "units.h"

#include <cstdint>
#include <type_traits>
#include <ratio>

#include "detail/units_combine.h"

namespace dla {
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr base_unit<Tag, Num, Den>::operator float() const noexcept { return value; }
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr base_unit<Tag, Num, Den>::operator float&() noexcept { return value; }

    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr decltype(auto) base_unit<Tag, Num, Den>::operator+=(const base_unit& rhs) {
        value += rhs.value;
        return *this;
    }
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr decltype(auto) base_unit<Tag, Num, Den>::operator-=(const base_unit& rhs) {
        value -= rhs.value;
        return *this;
    }
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr decltype(auto) base_unit<Tag, Num, Den>::operator*=(float rhs) {
        value *= rhs;
        return *this;
    }
    template<class Tag, std::intmax_t Num, std::intmax_t Den>
    constexpr decltype(auto) base_unit<Tag, Num, Den>::operator/=(float rhs) {
        value /= rhs;
        return *this;
    }

	template<class Tag, std::intmax_t Den>
    constexpr base_unit<Tag, 0, Den>::operator float() const noexcept { return value; }
	template<class Tag, std::intmax_t Den>
    constexpr base_unit<Tag, 0, Den>::operator float&() noexcept { return value; }

	template<class... Units>
    constexpr comp_unit<Units...>::operator float() const noexcept { return value; }
	template<class... Units>
    constexpr comp_unit<Units...>::operator float&() noexcept { return value; }

	template<class... Units>
    constexpr decltype(auto) comp_unit<Units...>::operator+=(const comp_unit& rhs) {
        value += rhs.value;
        return *this;
    }
	template<class... Units>
    constexpr decltype(auto) comp_unit<Units...>::operator-=(const comp_unit& rhs) {
        value -= rhs.value;
        return *this;
    }
	template<class... Units>
    constexpr decltype(auto) comp_unit<Units...>::operator*=(float rhs) {
        value *= rhs;
        return *this;
    }
	template<class... Units>
    constexpr decltype(auto) comp_unit<Units...>::operator/=(float rhs) {
        value /= rhs;
        return *this;
    }

    constexpr comp_unit<>::operator float() const noexcept { return value; }
    constexpr comp_unit<>::operator float&() noexcept { return value; }

	// Operations producing base units
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator-(const base_unit<Tag, Num, Den>& val) {
		return base_unit<Tag, Num, Den>{ -float(val) };
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator+(const base_unit<Tag, Num, Den>& lhs, const base_unit<Tag, Num, Den>& rhs) {
		return base_unit<Tag, Num, Den>{ float(rhs) + float(lhs) };
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator-(const base_unit<Tag, Num, Den>& lhs, const base_unit<Tag, Num, Den>& rhs) {
		return lhs + (-rhs);
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator*(const base_unit<Tag, Num, Den>& lhs, float rhs) {
		return base_unit<Tag, Num, Den>{ float(lhs) * rhs };
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator*(float lhs, const base_unit<Tag, Num, Den>& rhs) {
		return rhs * lhs;
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator/(const base_unit<Tag, Num, Den>& lhs, float rhs) {
		return base_unit<Tag, Num, Den>{ float(lhs) / rhs };
	}
	template<class Tag, std::intmax_t Num, std::intmax_t Den>
	constexpr auto operator/(float lhs, const base_unit<Tag, Num, Den>& rhs) {
		using unit = base_unit<Tag, Num, Den>;
		return detail::inverse_t<unit>{ 1.0f / float(rhs) } *lhs;
	}

	// Operations producing composite units
	template<class... Units>
	constexpr auto operator-(const comp_unit<Units...>& val) {
		return comp_unit<Units...>{ -float(val) };
	}
	template<class... Units>
	constexpr auto operator+(const comp_unit<Units...>& lhs, const comp_unit<Units...>& rhs) {
		return comp_unit<Units...>{ float(rhs) + float(lhs) };
	}
	template<class... Units>
	constexpr auto operator-(const comp_unit<Units...>& lhs, const comp_unit<Units...>& rhs) {
		return lhs + (-rhs);
	}
	template<class... Units>
	constexpr auto operator*(const comp_unit<Units...>& lhs, float rhs) {
		return comp_unit<Units...>{ float(lhs) * rhs };
	}
	template<class... Units>
	constexpr auto operator*(float lhs, const comp_unit<Units...>& rhs) {
		return rhs * lhs;
	}
	template<class... Units>
	constexpr auto operator/(const comp_unit<Units...>& lhs, float rhs) {
		return comp_unit<Units...>{ float(lhs) / rhs };
	}
	template<class... Units>
	constexpr auto operator/(float lhs, const comp_unit<Units...>& rhs) {
		using unit = comp_unit<Units...>;
		return detail::inverse_t<unit>{ 1.0f / float(rhs) } *lhs;
	}

	// Operations producing composite units from base units
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class rTag, std::intmax_t rNum, std::intmax_t rDen>
	constexpr auto operator*(const base_unit<lTag, lNum, lDen>& lhs, const base_unit<rTag, rNum, rDen>& rhs) {
		using lUnit = base_unit<lTag, lNum, lDen>;
		using rUnit = base_unit<rTag, rNum, rDen>;
		return detail::multiply_t<lUnit, rUnit>{ float(lhs) * float(rhs) };
	}
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class rTag, std::intmax_t rNum, std::intmax_t rDen>
	constexpr auto operator/(const base_unit<lTag, lNum, lDen>& lhs, const base_unit<rTag, rNum, rDen>& rhs) {
		return lhs * (1.0f / rhs);
	}
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class... Units>
	constexpr auto operator*(const base_unit<lTag, lNum, lDen>& lhs, const comp_unit<Units...>& rhs) {
		using lUnit = base_unit<lTag, lNum, lDen>;
		using rUnit = comp_unit<Units...>;
		return detail::multiply_t<lUnit, rUnit>{ float(lhs) * float(rhs) };
	}
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class... Units>
	constexpr auto operator/(const base_unit<lTag, lNum, lDen>& lhs, const comp_unit<Units...>& rhs) {
		return lhs * (1.0f / rhs);
	}
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class... Units>
	constexpr auto operator*(const comp_unit<Units...>& lhs, const base_unit<lTag, lNum, lDen>& rhs) {
		using lUnit = comp_unit<Units...>;
		using rUnit = base_unit<lTag, lNum, lDen>;
		return detail::multiply_t<lUnit, rUnit>{ float(lhs) * float(rhs) };
	}
	template<class lTag, std::intmax_t lNum, std::intmax_t lDen, class... Units>
	constexpr auto operator/(const comp_unit<Units...>& lhs, const base_unit<lTag, lNum, lDen>& rhs) {
		return lhs * (1.0f / rhs);
	}

	// Operations producing composite units from composite units
	template<class... lUnits, class... rUnits>
	constexpr auto operator*(const comp_unit<lUnits...>& lhs, const comp_unit<rUnits...>& rhs) {
		using lUnit = comp_unit<lUnits...>;
		using rUnit = comp_unit<rUnits...>;
		return detail::multiply_t<lUnit, rUnit>{ float(lhs) * float(rhs) };
	}
	template<class... lUnits, class... rUnits>
	constexpr auto operator/(const comp_unit<lUnits...>& lhs, const comp_unit<rUnits...>& rhs) {
		return lhs * (1.0f / rhs);
	}
}