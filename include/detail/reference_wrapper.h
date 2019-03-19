#pragma once

#include <type_traits>

namespace dla::detail {
	// Implementation for reference_wrapper directly from https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
	// Stripped off of the calling operator, magic and made into a literal type
	template <class T>
	class reference_wrapper {
	public:
		using type = T;

		constexpr reference_wrapper(T& val) noexcept
			: mPtr(std::addressof(val)) {}
		constexpr reference_wrapper(const reference_wrapper&) noexcept = default;
		
		constexpr reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;

		constexpr operator T& () const noexcept { return *mPtr; }
		constexpr T& get() const noexcept { return *mPtr; }

	private:
		T* mPtr;
	};

	template<class T>
	reference_wrapper(T&)->reference_wrapper<T>;

    template<class T>
    struct wrapped_reference {
        using type = std::conditional_t<
            std::is_reference_v<T>,
            reference_wrapper<std::remove_reference_t<T>>,
            T
        >;
    };
    template<class T>
    using wrapped_reference_t = typename wrapped_reference<T>::type;
}
