#pragma once

#include "vector_elements.h"

namespace dla::detail {
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(const T& px) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(px) {}

    template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 1>::vec_elements(T&& px) noexcept(std::is_nothrow_move_constructible_v<T>) :
        x(std::move(px)) {}

    template<class T>
    template<class U, typename>
    constexpr vec_elements<T, 1>::vec_elements(const vec_elements<U, 1>& val) :
        x(static_cast<T>(val.x)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 1>& vec_elements<T, 1>::operator=(const vec_elements<U, 1>& val) {
		static_cast<T>(x) = val.x;
		return *this;
	}


    
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(val), y(val) {}
    
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& px, const T& py) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(px), y(py) {}

    template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 2>::vec_elements(T&& px, T&& py) noexcept(std::is_nothrow_move_constructible_v<T>) :
        x(std::move(px)), y(std::move(py)) {}

    template<class T>
    template<class U, typename>
    constexpr vec_elements<T, 2>::vec_elements(const vec_elements<U, 2>& val) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 2>& vec_elements<T, 2>::operator=(const vec_elements<U, 2>& val) {
		static_cast<T>(x) = val.x;
		static_cast<T>(y) = val.y;
		return *this;
	}

    
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(val), y(val), z(val) {}
    
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& px, const T& py, const T& pz) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(px), y(py), z(pz) {}

    template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 3>::vec_elements(T&& px, T&& py, T&& pz) noexcept(std::is_nothrow_move_constructible_v<T>) :
        x(std::move(px)), y(std::move(py)), z(std::move(pz)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 3>::vec_elements(const vec_elements<U, 3>& val) :
		x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 3>& vec_elements<T, 3>::operator=(const vec_elements<U, 3>& val) {
		static_cast<T>(x) = val.x;
		static_cast<T>(y) = val.y;
		static_cast<T>(z) = val.z;
		return *this;
	}
    
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& val) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(val), y(val), z(val), w(val) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& px, const T& py, const T& pz, const T& pw) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(px), y(py), z(pz), w(pw) {}

    template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 4>::vec_elements(T&& px, T&& py, T&& pz, T&& pw) noexcept(std::is_nothrow_move_constructible_v<T>) :
        x(std::move(px)), y(std::move(py)), z(std::move(pz)), w(std::move(pw)) {}

    template<class T>
    template<class U, typename>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<U, 4>& val) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)), w(static_cast<T>(val.w)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 4>& vec_elements<T, 4>::operator=(const vec_elements<U, 4>& val) {
		static_cast<T>(x) = val.x;
		static_cast<T>(y) = val.y;
		static_cast<T>(z) = val.z;
		static_cast<T>(w) = val.w;
		return *this;
	}
}
