#pragma once

namespace dla::detail {
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(const T& px, init_coord_t) :
        x(px) {}
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(const T& pr, init_color_t) :
        r(pr) {}
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(const T& ps, init_tex_t) :
        s(ps) {}

    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(T&& px, init_coord_t) :
        x(std::move(px)) {}
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(T&& pr, init_color_t) :
        r(std::move(pr)) {}
    template<class T>
    constexpr vec_elements<T, 1>::vec_elements(T&& ps, init_tex_t) :
        s(std::move(ps)) {}

    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 1>::vec_elements(const vec_elements<U, 1>& val, init_coord_t) :
        x(static_cast<T>(val.x)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 1>::vec_elements(const vec_elements<U, 1>& val, init_color_t) :
        r(static_cast<T>(val.r)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 1>::vec_elements(const vec_elements<U, 1>& val, init_tex_t) :
        s(static_cast<T>(val.s)) {}

    
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& val) :
        x(val), y(val) {}
    
    template<class T>    
    constexpr vec_elements<T, 2>::vec_elements(const T& val, init_coord_t) :
        x(val), y(val) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& val, init_color_t) :
        r(val), g(val) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& val, init_tex_t) :
        s(val), t(val) {}
    
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& px, const T& py, init_coord_t) :
        x(px), y(py) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& pr, const T& pg, init_color_t) :
        r(pr), g(pg) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(const T& ps, const T& pt, init_tex_t) :
        s(ps), t(pt) {}

    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(T&& px, T&& py, init_coord_t) :
        x(std::move(px)), y(std::move(py)) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(T&& pr, T&& pg, init_color_t) :
        r(std::move(pr)), g(std::move(pg)) {}
    template<class T>
    constexpr vec_elements<T, 2>::vec_elements(T&& ps, T&& pt, init_tex_t) :
        s(std::move(ps)), t(std::move(pt)) {}

    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 2>::vec_elements(const vec_elements<U, 2>& val, init_coord_t) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 2>::vec_elements(const vec_elements<U, 2>& val, init_color_t) :
        r(static_cast<T>(val.r)), g(static_cast<T>(val.y)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 2>::vec_elements(const vec_elements<U, 2>& val, init_tex_t) :
        s(static_cast<T>(val.s)), t(static_cast<T>(val.t)) {}

    
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& val) :
        x(val), y(val), z(val) {}
    
    template<class T>    
    constexpr vec_elements<T, 3>::vec_elements(const T& val, init_coord_t) :
        x(val), y(val), z(val) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& val, init_color_t) :
        r(val), g(val), b(val) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& val, init_tex_t) :
        s(val), t(val), p(val) {}
    
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& px, const T& py, const T& pz, init_coord_t) :
        x(px), y(py), z(pz) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& pr, const T& pg, const T& pb, init_color_t) :
        r(pr), g(pg), b(pb) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(const T& ps, const T& pt, const T& pp, init_tex_t) :
        s(ps), t(pt), p(pp) {}

    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(T&& px, T&& py, T&& pz, init_coord_t) :
        x(std::move(px)), y(std::move(py)), z(std::move(pz)) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(T&& pr, T&& pg, T&& pb, init_color_t) :
        r(std::move(pr)), g(std::move(pg)), b(std::move(pb)) {}
    template<class T>
    constexpr vec_elements<T, 3>::vec_elements(T&& ps, T&& pt, T&& pp, init_tex_t) :
        s(std::move(ps)), t(std::move(pt)), p(std::move(pp)) {}

    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 3>::vec_elements(const vec_elements<U, 3>& val, init_coord_t) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 3>::vec_elements(const vec_elements<U, 3>& val, init_color_t) :
        r(static_cast<T>(val.r)), g(static_cast<T>(val.g)), b(static_cast<T>(val.b)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 3>::vec_elements(const vec_elements<U, 3>& val, init_tex_t) :
        s(static_cast<T>(val.s)), t(static_cast<T>(val.t)), p(static_cast<T>(val.p)) {}

    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& val) :
        x(val), y(val), z(val), w(val) {}
    
    template<class T>    
    constexpr vec_elements<T, 4>::vec_elements(const T& val, init_coord_t) :
        x(val), y(val), z(val), w(val) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& val, init_color_t) :
        r(val), g(val), b(val), a(val) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& val, init_tex_t) :
        s(val), t(val), p(val), q(val) {}
    
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& px, const T& py, const T& pz, const T& pw, init_coord_t) :
        x(px), y(py), z(pz), w(pw) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& pr, const T& pg, const T& pb, const T& pa, init_color_t) :
        r(pr), g(pg), b(pb), a(pa) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(const T& ps, const T& pt, const T& pp, const T& pq, init_tex_t) :
        s(ps), t(pt), p(pp), q(pq) {}

    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& px, T&& py, T&& pz, T&& pw, init_coord_t) :
        x(std::move(px)), y(std::move(py)), z(std::move(pz)), w(std::move(pw)) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& pr, T&& pg, T&& pb, T&& pa, init_color_t) :
        r(std::move(pr)), g(std::move(pg)), b(std::move(pb)), a(std::move(pa)) {}
    template<class T>
    constexpr vec_elements<T, 4>::vec_elements(T&& ps, T&& pt, T&& pp, T&& pq, init_tex_t) :
        s(std::move(ps)), t(std::move(pt)), p(std::move(pp)), q(std::move(pq)) {}

    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<U, 4>& val, init_coord_t) :
        x(static_cast<T>(val.x)), y(static_cast<T>(val.y)), z(static_cast<T>(val.z)), w(static_cast<T>(val.w)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<U, 4>& val, init_color_t) :
        r(static_cast<T>(val.r)), g(static_cast<T>(val.g)), b(static_cast<T>(val.b)), a(static_cast<T>(val.a)) {}
    template<class T>
    template<class U, class>
    constexpr vec_elements<T, 4>::vec_elements(const vec_elements<U, 4>& val, init_tex_t) :
        s(static_cast<T>(val.s)), t(static_cast<T>(val.t)), p(static_cast<T>(val.p)), q(static_cast<T>(val.q)) {}
}
