#pragma once

#include <type_traits>
#include <memory>
#include <utility>

namespace dla::detail {
	// Dumbed down version of std::reference_wrapper which has better reference-semantics
	// Required only to be able to use references in a union
	template <class T>
	class reference_wrapper {
	public:
		constexpr explicit reference_wrapper(T& val) noexcept
			: mPtr(std::addressof(val)) {}

		constexpr reference_wrapper(reference_wrapper&&) noexcept = default;
		constexpr reference_wrapper(const reference_wrapper&) noexcept = default;
		constexpr reference_wrapper& operator=(reference_wrapper&&) noexcept = default;
		constexpr reference_wrapper& operator=(const reference_wrapper&) noexcept = default;

		constexpr reference_wrapper& operator=(T&& val) {
			*mPtr = std::move(val);
			return *this;
		}
		constexpr reference_wrapper& operator=(const T& val) {
			*mPtr = val;
			return *this;
		}

		constexpr operator T& () noexcept { return *mPtr; }
		constexpr operator const T& () const noexcept { return *mPtr; }

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
