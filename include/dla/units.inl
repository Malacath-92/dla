#pragma once

#include "units.h"

#include <cstdint>
#include <type_traits>
#include <ratio>

#include "detail/units_combine.h"

namespace dla {
    template<class Tag>
    constexpr base_unit<Tag>::operator underlying_t() const noexcept { return value; }
    template<class Tag>
    constexpr base_unit<Tag>::operator underlying_t&() noexcept { return value; }

    template<class Tag>
    constexpr decltype(auto) base_unit<Tag>::operator+=(const base_unit& rhs) {
        value += rhs.value;
        return *this;
    }
    template<class Tag>
    constexpr decltype(auto) base_unit<Tag>::operator-=(const base_unit& rhs) {
        value -= rhs.value;
        return *this;
    }
    template<class Tag>
    constexpr decltype(auto) base_unit<Tag>::operator*=(underlying_t rhs) {
        value *= rhs;
        return *this;
    }
    template<class Tag>
    constexpr decltype(auto) base_unit<Tag>::operator/=(underlying_t rhs) {
        value /= rhs;
        return *this;
    }

	template<class... Tags>
    constexpr comp_unit<Tags...>::operator underlying_t() const noexcept { return value; }
	template<class... Tags>
    constexpr comp_unit<Tags...>::operator underlying_t&() noexcept { return value; }

	template<class... Tags>
    constexpr decltype(auto) comp_unit<Tags...>::operator+=(const comp_unit& rhs) {
        value += rhs.value;
        return *this;
    }
	template<class... Tags>
    constexpr decltype(auto) comp_unit<Tags...>::operator-=(const comp_unit& rhs) {
        value -= rhs.value;
        return *this;
    }
	template<class... Tags>
    constexpr decltype(auto) comp_unit<Tags...>::operator*=(underlying_t rhs) {
        value *= rhs;
        return *this;
    }
	template<class... Tags>
    constexpr decltype(auto) comp_unit<Tags...>::operator/=(underlying_t rhs) {
        value /= rhs;
        return *this;
    }

    constexpr comp_unit<>::operator underlying_t() const noexcept { return value; }
    constexpr comp_unit<>::operator underlying_t&() noexcept { return value; }

	// Operations producing base units
	template<class Tag>
	constexpr auto operator+(const base_unit<Tag>& val) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return base_unit<Tag>{ +underlying_t(val) };
	}
	template<class Tag>
	constexpr auto operator-(const base_unit<Tag>& val) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return base_unit<Tag>{ -underlying_t(val) };
	}
	template<class Tag>
	constexpr auto operator+(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return base_unit<Tag>{ underlying_t(rhs) + underlying_t(lhs) };
	}
	template<class Tag>
	constexpr auto operator-(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		return lhs + (-rhs);
	}
	template<class Tag>
	constexpr auto operator*(const base_unit<Tag>& lhs, float rhs) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return base_unit<Tag>{ underlying_t(lhs) * rhs };
	}
	template<class Tag>
	constexpr auto operator*(float lhs, const base_unit<Tag>& rhs) {
		return rhs * lhs;
	}
	template<class Tag>
	constexpr auto operator/(const base_unit<Tag>& lhs, float rhs) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return base_unit<Tag>{ underlying_t(lhs) / rhs };
	}
	template<class Tag>
	constexpr auto operator/(float lhs, const base_unit<Tag>& rhs) {
		using unit = base_unit<Tag>;
		using underlying_t = typename unit::underlying_t;
		return detail::inverse_t<unit>{ 1.0f / underlying_t(rhs) } * lhs;
	}

	// Operations producing composite units
	template<class... Tags>
	constexpr auto operator+(const comp_unit<Tags...>& val) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return comp_unit<Tags...>{ +underlying_t(val) };
	}
	template<class... Tags>
	constexpr auto operator-(const comp_unit<Tags...>& val) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return comp_unit<Tags...>{ -underlying_t(val) };
	}
	template<class... Tags>
	constexpr auto operator+(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return comp_unit<Tags...>{ underlying_t(rhs) + underlying_t(lhs) };
	}
	template<class... Tags>
	constexpr auto operator-(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		return lhs + (-rhs);
	}
	template<class... Tags>
	constexpr auto operator*(const comp_unit<Tags...>& lhs, float rhs) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return comp_unit<Tags...>{ underlying_t(lhs) * rhs };
	}
	template<class... Tags>
	constexpr auto operator*(float lhs, const comp_unit<Tags...>& rhs) {
		return rhs * lhs;
	}
	template<class... Tags>
	constexpr auto operator/(const comp_unit<Tags...>& lhs, float rhs) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return comp_unit<Tags...>{ underlying_t(lhs) / rhs };
	}
	template<class... Tags>
	constexpr auto operator/(float lhs, const comp_unit<Tags...>& rhs) {
		using unit = comp_unit<Tags...>;
		using underlying_t = typename unit::underlying_t;
		return detail::inverse_t<unit>{ 1.0f / underlying_t(rhs) } *lhs;
	}

	// Operations producing composite units from base units
	template<class lTag, class rTag>
	constexpr auto operator*(const base_unit<lTag>& lhs, const base_unit<rTag>& rhs) {
		using lUnit = base_unit<lTag>;
		using rUnit = base_unit<rTag>;
		using lUnderlying_t = typename lUnit::underlying_t;
		using rUnderlying_t = typename rUnit::underlying_t;
		return detail::multiply_t<lUnit, rUnit>{ lUnderlying_t(lhs) * rUnderlying_t(rhs) };
	}
	template<class lTag, class rTag>
	constexpr auto operator/(const base_unit<lTag>& lhs, const base_unit<rTag>& rhs) {
		return lhs * (1.0f / rhs);
	}
	template<class Tag, class... Tags>
	constexpr auto operator*(const base_unit<Tag>& lhs, const comp_unit<Tags...>& rhs) {
		using lUnit = base_unit<Tag>;
		using rUnit = comp_unit<Tags...>;
		using lUnderlying_t = typename lUnit::underlying_t;
		using rUnderlying_t = typename rUnit::underlying_t;
		return detail::multiply_t<lUnit, rUnit>{ lUnderlying_t(lhs) * rUnderlying_t(rhs) };
	}
	template<class Tag, class... Tags>
	constexpr auto operator/(const base_unit<Tag>& lhs, const comp_unit<Tags...>& rhs) {
		return lhs * (1.0f / rhs);
	}
	template<class Tag, class... Tags>
	constexpr auto operator*(const comp_unit<Tags...>& lhs, const base_unit<Tag>& rhs) {
		using lUnit = comp_unit<Tags...>;
		using rUnit = base_unit<Tag>;
		using lUnderlying_t = typename lUnit::underlying_t;
		using rUnderlying_t = typename rUnit::underlying_t;
		return detail::multiply_t<lUnit, rUnit>{ lUnderlying_t(lhs) * rUnderlying_t(rhs) };
	}
	template<class Tag, class... Tags>
	constexpr auto operator/(const comp_unit<Tags...>& lhs, const base_unit<Tag>& rhs) {
		return lhs * (1.0f / rhs);
	}

	// Operations producing composite units from composite units
	template<class... lTags, class... rTags>
	constexpr auto operator*(const comp_unit<lTags...>& lhs, const comp_unit<rTags...>& rhs) {
		using lUnit = comp_unit<lTags...>;
		using rUnit = comp_unit<rTags...>;
		using lUnderlying_t = typename lUnit::underlying_t;
		using rUnderlying_t = typename rUnit::underlying_t;
		return detail::multiply_t<lUnit, rUnit>{ lUnderlying_t(lhs) * rUnderlying_t(rhs) };
	}
	template<class... lTags, class... rTags>
	constexpr auto operator/(const comp_unit<lTags...>& lhs, const comp_unit<rTags...>& rhs) {
		return lhs * (1.0f / rhs);
	}

	// Comparison and relational operations
	template<class Tag>
	constexpr auto operator==(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) == underlying_t(rhs);
	}
	template<class Tag>
	constexpr auto operator!=(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) != underlying_t(rhs);
	}
	template<class Tag>
	constexpr auto operator>(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) > underlying_t(rhs);
	}
	template<class Tag>
	constexpr auto operator<(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) < underlying_t(rhs);
	}
	template<class Tag>
	constexpr auto operator>=(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) >= underlying_t(rhs);
	}
	template<class Tag>
	constexpr auto operator<=(const base_unit<Tag>& lhs, const base_unit<Tag>& rhs) {
		using underlying_t = typename base_unit<Tag>::underlying_t;
		return underlying_t(lhs) <= underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator==(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) == underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator!=(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) != underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator>(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) > underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator<(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) < underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator>=(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) >= underlying_t(rhs);
	}
	template<class... Tags>
	constexpr auto operator<=(const comp_unit<Tags...>& lhs, const comp_unit<Tags...>& rhs) {
		using underlying_t = typename comp_unit<Tags...>::underlying_t;
		return underlying_t(lhs) <= underlying_t(rhs);
	}
}
