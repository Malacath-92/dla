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
		x = val.x;
		return *this;
	}

	template<class T>
	constexpr auto vec_elements<T, 1>::pod() & {
        struct vec_pod
        {
            value_type& x;
        };
        return vec_pod{ x };
	}

	template<class T>
	constexpr auto vec_elements<T, 1>::pod() const & {
        struct vec_pod
        {
            const value_type& x;
        };
        return vec_pod{ x };
	}

	template<class T>
	constexpr auto vec_elements<T, 1>::pod() && {
        struct vec_pod
        {
            value_type x;
        };
        return vec_pod{ std::move(x) };
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
		x = val.x;
		y = val.y;
		return *this;
	}

	template<class T>
	constexpr auto vec_elements<T, 2>::pod() & {
        struct vec_pod
        {
            value_type& x;
            value_type& y;
        };
        return vec_pod{ x, y };
	}

	template<class T>
	constexpr auto vec_elements<T, 2>::pod() const & {
        struct vec_pod
        {
            const value_type& x;
            const value_type& y;
        };
        return vec_pod{ x, y };
	}

	template<class T>
	constexpr auto vec_elements<T, 2>::pod() && {
        struct vec_pod
        {
            value_type x;
            value_type y;
        };
        return vec_pod{ std::move(x), std::move(y) };
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
    constexpr vec_elements<T, 3>::vec_elements(const vec_elements<T, 2>& vxy, T&& pz) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(vxy.x), y(vxy.y), z(std::move(pz)) {}
    
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(T&& px, const vec_elements<T, 2>& vyz) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(std::move(px)), y(vyz.y), z(vyz.z) {}


	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 3>::vec_elements(const vec_elements<U, 3>& val) :
		x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 3>& vec_elements<T, 3>::operator=(const vec_elements<U, 3>& val) {
		x = val.x;
		y = val.y;
		z = val.z;
		return *this;
	}

	template<class T>
	constexpr auto vec_elements<T, 3>::pod() & {
        struct vec_pod
        {
            value_type& x;
            value_type& y;
            value_type& z;
        };
        return vec_pod{ x, y, z };
	}

	template<class T>
	constexpr auto vec_elements<T, 3>::pod() const & {
        struct vec_pod
        {
            const value_type& x;
            const value_type& y;
            const value_type& z;
        };
        return vec_pod{ x, y, z };
	}

	template<class T>
	constexpr auto vec_elements<T, 3>::pod() && {
        struct vec_pod
        {
            value_type x;
            value_type y;
            value_type z;
        };
        return vec_pod{ std::move(x), std::move(y), std::move(z) };
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
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<T, 2>& vxy, T&& pz, T&& pw) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(vxy.x), y(vxy.y), z(std::move(pz)), w(std::move(pw)) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& px, const vec_elements<T, 2>& vyz, T&& pw) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(std::move(px)), y(vyz.y), z(vyz.z), w(std::move(pw)) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& px, T&& py, const vec_elements<T, 2>& vzw) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(std::move(px)), y(std::move(py)), z(vzw.z), w(vzw.w) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<T, 2>& vxy, const vec_elements<T, 2>& vzw) noexcept(std::is_nothrow_copy_constructible_v<T>) :
        x(vxy.x), y(vxy.y), z(vzw.z), w(vzw.w)  {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<T, 3>& vxyz, T&& pw) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(vxyz.x), y(vxyz.y), z(vxyz.z), w(std::move(pw)) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& px, const vec_elements<T, 3>& vyzw) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_copy_constructible_v<T>) :
        x(std::move(px)), y(vyzw.y), z(vyzw.z), w(vyzw.w) {}


    template<class T>
    template<class U, typename>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<U, 4>& val) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)), w(static_cast<T>(val.w)) {}

	template<class T>
	template<class U, typename>
	constexpr vec_elements<T, 4>& vec_elements<T, 4>::operator=(const vec_elements<U, 4>& val) {
		x = val.x;
		y = val.y;
		z = val.z;
		w = val.w;
		return *this;
	}
    
	template<class T>
	constexpr auto vec_elements<T, 4>::pod() & {
        struct vec_pod
        {
            value_type& x;
            value_type& y;
            value_type& z;
            value_type& w;
        };
        return vec_pod{ x, y, z, w };
	}

	template<class T>
	constexpr auto vec_elements<T, 4>::pod() const & {
        struct vec_pod
        {
            const value_type& x;
            const value_type& y;
            const value_type& z;
            const value_type& w;
        };
        return vec_pod{ x, y, z, w };
	}

	template<class T>
	constexpr auto vec_elements<T, 4>::pod() && {
        struct vec_pod
        {
            value_type x;
            value_type y;
            value_type z;
            value_type w;
        };
        return vec_pod{ std::move(x), std::move(y), std::move(z), std::move(w) };
	}
}
