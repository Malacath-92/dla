#include "detail.h"
#include "vector_math.h"

namespace unit::vector {

#ifdef INDEXING_OPERATOR_THROWS_OUT_OF_BOUNDS
    inline constexpr bool vec_index_operator_is_noexcept = false;
#else
    inline constexpr bool vec_index_operator_is_noexcept = true;
#endif

#define MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class U> \
    constexpr decltype(auto) operator op##=(const U& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }
#define MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(op) \
    template<class U> \
    constexpr decltype(auto) operator op##=(const vec<U, length>& rhs) noexcept { \
        *this = std::move(*this op rhs); \
        return *this; \
    }

    template<class T, std::size_t N>
    struct vec : detail::vec_elements<T, N> {
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
		using iterator = detail::vec_iterator<vec, N>;
		using const_iterator = detail::vec_iterator<const vec, N>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        static constexpr std::size_t length = N;

        using vec_elements = detail::vec_elements<T, N>;
        using vec_elements::vec_elements;
        template<class U>
        constexpr explicit vec(const vec<U, N>& val) :
            vec_elements(static_cast<const detail::vec_elements<U, N>&>(val)) {}

        constexpr const_reference operator[](std::size_t idx) const noexcept(vec_index_operator_is_noexcept) {
            if (idx == 0) return this->x;
            else if constexpr (N > 1) {
                if (idx == 1) return this->y;
                else if constexpr (N > 2) {
                    if (idx == 2) return this->z;
                    else if constexpr (N > 3) {
                        if (idx == 3) return this->w;
                    }
                }
            }
            if constexpr (!vec_index_operator_is_noexcept) {
                throw std::out_of_range("Vector index out of rance!");
            }
            declare_unreachable();
        }
        constexpr reference operator[](std::size_t idx) noexcept(vec_index_operator_is_noexcept) {
            return const_cast<reference>(static_cast<const vec*>(this)->operator[](idx));
        }

        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(+)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(-)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(*)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(/)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(%)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(&)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(|)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(^)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(<<)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(>>)

        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(+)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(-)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(*)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(/)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(%)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(&)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(|)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(^)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(<<)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(>>)

		constexpr iterator begin() noexcept { return { *this, 0 }; }
		constexpr const_iterator begin() const noexcept { return { *this, 0 }; }
		constexpr iterator end() noexcept { return { *this, N }; }
		constexpr const_iterator end() const noexcept { return { *this, N }; }

		constexpr reverse_iterator rbegin() noexcept { return { *this, N - 1 }; }
		constexpr const_reverse_iterator rbegin() const noexcept { return { *this, N - 1 }; }
		constexpr reverse_iterator rend() noexcept { return { *this, -1 }; }
		constexpr const_reverse_iterator rend() const noexcept { return { *this, -1 }; }

		constexpr const_iterator cbegin() noexcept { return { *this, 0 }; }
		constexpr const_iterator cend() const noexcept { return { *this, N }; }
		constexpr const_reverse_iterator crbegin() noexcept { return { *this, N - 1 }; }
		constexpr const_reverse_iterator crend() noexcept { return { *this, -1 }; }
    };

    // Size 1 vectors implicitly convert to their value_type, otherwise they are identical in function
    template<class T>
    struct vec<T, 1> : detail::vec_elements<T, 1> {
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
		using iterator = detail::vec_iterator<vec, 1>;
		using const_iterator = detail::vec_iterator<const vec, 1>;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        static constexpr std::size_t length = 1;

        using vec_elements = detail::vec_elements<T, 1>;
        using vec_elements::vec_elements;
        template<class U>
        constexpr explicit vec(const vec<U, 1>& val) :
            vec_elements(static_cast<const detail::vec_elements<U, 1>&>(val)) {}

        constexpr const_reference operator[](std::size_t idx) const noexcept(vec_index_operator_is_noexcept) {
            if (idx == 0) return this->x;
            if constexpr (!vec_index_operator_is_noexcept) {
                throw std::out_of_range("Vector index out of rance!");
            }
            declare_unreachable();
        }
        constexpr reference operator[](std::size_t idx) noexcept(vec_index_operator_is_noexcept) {
            return const_cast<reference>(static_cast<const vec*>(this)->operator[](idx));
        }

        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(+)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(-)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(*)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(/)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(%)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(&)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(|)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(^)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(<<)
        MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR(>>)

        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(+)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(-)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(*)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(/)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(%)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(&)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(|)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(^)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(<<)
        MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR(>>)

        constexpr operator value_type() const noexcept { return this->x; }
        constexpr operator reference() noexcept { return this->x; }

		constexpr iterator begin() noexcept { return { *this, 0 }; }
		constexpr const_iterator begin() const noexcept { return { *this, 0 }; }
		constexpr iterator end() noexcept { return { *this, 1 }; }
		constexpr const_iterator end() const noexcept { return { *this, 1 }; }

		constexpr reverse_iterator rbegin() noexcept { return { *this, 0 }; }
		constexpr const_reverse_iterator rbegin() const noexcept { return { *this, 0 }; }
		constexpr reverse_iterator rend() noexcept { return { *this, -1 }; }
		constexpr const_reverse_iterator rend() const noexcept { return { *this, -1 }; }

		constexpr const_iterator cbegin() noexcept { return { *this, 0 }; }
		constexpr const_iterator cend() const noexcept { return { *this, 1 }; }
		constexpr const_reverse_iterator crbegin() noexcept { return { *this, 0 }; }
		constexpr const_reverse_iterator crend() noexcept { return { *this, -1 }; }
    };

#undef MAKE_VECTOR_VECTOR_BINARY_ASSIGNEMT_OPERATOR
#undef MAKE_VECTOR_SCALAR_BINARY_ASSIGNEMT_OPERATOR

    template<class T>
    using tvec1 = vec<T, 1>;
    template<class T>
    using tvec2 = vec<T, 2>;
    template<class T>
    using tvec3 = vec<T, 3>;
    template<class T>
    using tvec4 = vec<T, 4>;

    template<class T> vec(const T&, const T&) -> vec<T, 2>;
    template<class T> vec(const T&, const T&, const T&) -> vec<T, 3>;
    template<class T> vec(const T&, const T&, const T&, const T&) -> vec<T, 4>;
    template<class T> vec(T&&, T&&) -> vec<T, 2>;
    template<class T> vec(T&&, T&&, T&&) -> vec<T, 3>;
    template<class T> vec(T&&, T&&, T&&, T&&) -> vec<T, 4>;
}