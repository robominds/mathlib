
#pragma once

#include <quaternion.hpp>
#include <vectorMath.hpp>

template<typename T>
quaternion<T> conjugate(const quaternion<T> &q) {
    quaternion<T> result(q);

    result.v() = -q.v();
    
    return result;
}

template<typename T>
quaternion<T> operator*(const quaternion<T> &q1, const quaternion<T> &q2) {

    quaternion<T> result;
    result.s() = q1.s()*q2.s()-dot(q1.v(), q2.v());
    result.v() = q1.s()*q2.v() + q2.s()*q1.v() + cross(q1.v(), q2.v());
    
    return result;
}

// Rotation of a vector by a quaternion is the vector part of (q * Pure(v) * q^-1)
template<typename T>
vector<3, T> operator*(const quaternion<T> &q, const vector<3, T> &v) {
    
    return (q*quaternion<T>(v)*conjugate(q)).v();
}
