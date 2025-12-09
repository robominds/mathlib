
#pragma once

#include "vectorMath.hpp"

template<size_t N, typename T>
vector<N, T> normalize(vector<N, T> &v) {

    return v / sqrt(dot(v,v));
}
