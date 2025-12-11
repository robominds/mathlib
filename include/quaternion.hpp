
#pragma once

#include <stddef.h>
#include <initializer_list>
#include <math.h>
#include <vector.hpp>

namespace mathlib {

template<typename T>
class quaternion {
    public:
        quaternion(void);
        quaternion(T s, vector<3, T> v);
        quaternion(T *vals, bool normalize = true);
        quaternion(std::initializer_list<T> vals, bool normalize = true);
        quaternion(const quaternion<T> &q);

        // Pure quaternion constructor
        explicit quaternion(const vector<3, T> v);
        
        inline T& operator()(size_t indx);
        inline const T& operator()(size_t indx) const;

        void normalize(void);

        inline T& s(void);
        inline const T& s(void) const;
        inline T& v(size_t indx);
        inline const T& v(size_t indx) const;
        inline vector<3, T>& v(void);
        inline const vector<3, T>& v(void) const;

    private:
        T _s;
        vector<3, T> _v;
};

template<typename T>
quaternion<T>::quaternion(void) {

    _s = T(1);
    _v(0) = T(0);
    _v(1) = T(0);
    _v(2) = T(0);
}

template<typename T>
quaternion<T>::quaternion(T angle, vector<3, T> v) {
    T vNorm = sqrt(dot(v,v));
    T halfAng = angle/T(2);

    _s = static_cast<T>(cos(halfAng));
    _v = v/vNorm*sin(halfAng);
}

template<typename T>
quaternion<T>::quaternion(T *vals, bool normalize) {

    _s = vals[0];
    _v(0) = vals[1];
    _v(1) = vals[2];
    _v(2) = vals[3];
}

template<typename T>
quaternion<T>::quaternion(std::initializer_list<T> vals, bool normalize) {

    const T *it = vals.begin();

    _s = *(it++);
    _v(0) = *(it++);
    _v(1) = *(it++);
    _v(2) = *(it++);
}

template<typename T>
quaternion<T>::quaternion(const quaternion<T> &q) {

    _s = q.s();
    _v = q.v();
}

template<typename T>
quaternion<T>::quaternion(const vector<3, T> v) {

    _s = T(0);
    _v = v;
}

template<typename T>
inline T& quaternion<T>::operator()(size_t indx) {

    if(indx) {
        return _v(indx+1);
    } else {
        return _s;
    }
}
template<typename T>
inline const T& quaternion<T>::operator()(size_t indx) const {
    if(indx) {
        return _v(indx+1);
    } else {
        return _s;
    }
}

template<typename T>
void quaternion<T>::normalize(void) {
    T mag;
    T magSqrd(_s*_s);

    for(size_t i=0; i<3; i++) {
        magSqrd += _v(i)*_v(i);
    }
    mag = sqrt(magSqrd);

    if(magSqrd > 0) {
        _s /= mag;
        for(size_t i=0; i<3; i++) {
            v(i) /= mag;
        }
    } else {
        _s = T(1);
        _v(0) = T(0);
        _v(1) = T(0);
        _v(2) = T(0);
    }

}

template<typename T>
inline T& quaternion<T>::s(void) {

    return _s;
}

template<typename T>
inline const T& quaternion<T>::s(void) const {

    return _s;
}

template<typename T>
inline vector<3, T>& quaternion<T>::v(void) {

    return _v;
}

template<typename T>
inline T& quaternion<T>::v(size_t indx) {

    return _v(indx);
}

template<typename T>
inline const vector<3, T>& quaternion<T>::v(void) const {

    return _v;
}

template<typename T>
inline const T& quaternion<T>::v(size_t indx) const {

    return _v(indx);
}

}  // namespace mathlib
