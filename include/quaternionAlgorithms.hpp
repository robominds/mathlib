
#pragma once

#include <quaternionMath.hpp>

template<typename T>
matrix<3, 3, T> dcm(const quaternion<T> &q) {

    matrix<3, 3, T> result;

    result(0, 0) = 1 - 2*(q.v(1)*q.v(1) + q.v(2)*q.v(2));
    result(0, 1) = 2*(q.v(0)*q.v(1) - q.v(2)*q.s());
    result(0, 2) = 2*(q.v(0)*q.v(2) + q.v(1)*q.s());
    result(1, 0) = 2*(q.v(0)*q.v(1) + q.v(2)*q.s());
    result(1, 1) = 1 - 2*(q.v(1)*q.v(1) + q.v(2)*q.v(2));
    result(1, 2) = 2*(q.v(1)*q.v(2) - q.v(0)*q.s());
    result(2, 0) = 2*(q.v(0)*q.v(2) - q.v(1)*q.s());
    result(2, 1) = 2*(q.v(1)*q.v(2) + q.v(0)*q.s());
    result(2, 2) = 1 - 2*(q.v(1)*q.v(1) + q.v(2)*q.v(2));

    return result;
}
