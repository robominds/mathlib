
#pragma once

#include "vector.hpp"

template<size_t N, typename T>
T dot(const vector<N, T> &v1, const vector<N, T> &v2) {
    T result = T(0);

    for(size_t i=0; i<N; i++) {
        result += v1(i)*v2(i);
    }

    return result;
}

template<typename T>
vector<3, T> cross(const vector<3, T> &v1, const vector<3, T> &v2) {
    vector<3, T> result;

    result(0) = v1(1)*v2(2)-v1(2)*v2(1);
    result(1) = v1(2)*v2(0)-v1(0)*v2(2);
    result(2) = v1(0)*v2(1)-v1(1)*v2(0);

    return result;
}

template<size_t N, typename T>
vector<N, T> operator*(const vector<N, T> &v, T s) {
    vector<N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i) = v(i)*s;
    }
    
    return result;
}

template<size_t N, typename T>
vector<N, T> operator/(const vector<N, T> &v, T s) {
    vector<N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i) = v(i)/s;
    }
    
    return result;
}

template<size_t N, typename T>
vector<N, T> operator+(const vector<N, T> &v, T s) {
    vector<N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i) = v(i)+s;
    }
    
    return result;
}

template<size_t N, typename T>
vector<N, T> operator-(const vector<N, T> &v, T s) {
    vector<N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i) = v(i)-s;
    }
    
    return result;
}

template<size_t N, typename T>
vector<N, T> operator*(T s, const vector<N, T> v) {

    return v*s;
}

template<size_t N, typename T>
vector<N, T> operator+(T s, const vector<N, T> &v) {

    return v+s;
}

template<size_t N, typename T>
vector<N, T> operator-(T s, const vector<N, T> &v) {
    
    return v-s;
}

template<size_t N, typename T>
vector<N, T>  operator-(const vector<N, T> &v1) {
    vector<N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i) = -v1(i);
    }
    return result;
}

template<size_t N, typename T>
void operator*=(const vector<N, T> &v, T s) {

    for(size_t i=0; i<N; i++) {
        v(i) *= s;
    }
}

template<size_t N, typename T>
void operator/=(const vector<N, T> &v, T s) {

    for(size_t i=0; i<N; i++) {
        v(i) /= s;
    }
}

template<size_t N, typename T>
void operator+=(const vector<N, T> &v, T s) {

    for(size_t i=0; i<N; i++) {
        v(i) += s;
    }
}

template<size_t N, typename T>
void operator-=(const vector<N, T> &v, T s) {

    for(size_t i=0; i<N; i++) {
        v(i) -= s;
    }
}

template<size_t N, typename T>
vector<N, T> operator+(const vector<N, T> &v1, const vector<N, T> &v2) {
    vector<N, T> result(v1);

    for(size_t i=0; i<N; i++) {
        result(i) += v2(i);
    }
    
    return result;
}

template<size_t N, typename T>
vector<N, T> operator-(const vector<N, T> &v1, const vector<N, T> &v2) {
    vector<N, T> result(v1);

    for(size_t i=0; i<N; i++) {
        result(i) -= v2(i);
    }
    
    return result;
}

template<size_t N, typename T>
void operator+=(const vector<N, T> &v1, const vector<N, T> &v2) {

    for(size_t i=0; i<N; i++) {
        v1(i) += v2(i);
    }
}

template<size_t N, typename T>
void operator-=(const vector<N, T> &v1, const vector<N, T> &v2) {

    for(size_t i=0; i<N; i++) {
        v1(i) -= v2(i);
    }
}
