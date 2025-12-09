
#pragma once

#include "matrix.hpp"
#include "vector.hpp"

template<size_t N, typename T>
matrix<N, N, T> eye(void) {
    matrix<N, N, T> result;

    for(size_t i=0; i<N; i++) {
        result(i,i) = T(1.0);
    }
    return result;
}

template<size_t R, size_t C, typename T, size_t CC>
matrix<R, C, T> multiply(const matrix<R, CC, T> &mat1, const matrix<CC, C, T> &mat2, matrix<R, C, T> &result) {

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<CC; j++) {
            result(i,j) = T(0);
            for(size_t k=0; k<C; k++) {
                result(i,j) += mat1(i,k)*mat2(k,j);
            }
        }
    }
    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator*(const matrix<R, C, T> &mat, T val) {
    matrix<R, C, T> result;

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i,j) = mat(i,j)*val;
        }
    }
    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator/(const matrix<R, C, T> &mat, T val) {
    matrix<R, C, T> result;

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i,j) = mat(i,j)/val;
        }
    }
    return result;
}

template<size_t R, size_t C, typename T, size_t CC>
matrix<R, C, T> operator*(const matrix<R, CC, T> &mat1, const matrix<CC, C, T> &mat2) {
    matrix<R, CC, T> result;

    multiply(mat1, mat2, result);
    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator+(const matrix<R, C, T> &mat, T &val) {

    matrix<R, C, T> result;
    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i,j) =  mat(i,j)+val;
        }
    }
    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator+(const matrix<R, C, T> &mat1, const matrix<R, C, T> &mat2) {
    matrix<R, C, T> result;

    multiply(mat1, mat2, result);

    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator-(const matrix<R, C, T> &mat, T &val) {

    matrix<R, C, T> result;
    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i,j) =  mat(i,j)-val;
        }
    }
    return result;
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator-(const matrix<R, C, T> &mat1, const matrix<R, C, T> &mat2) {

    matrix<R, C, T> result;
    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i,j) =  mat1(i,j)-mat2(i,j);
        }
    }
    return result;
}

template<size_t R, size_t C, typename T>
void operator*=(const matrix<R, C, T> &mat, T val) {

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat(i,j) *= val;
        }
    }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T> operator/=(const matrix<R, C, T> &mat, T val) {
    matrix<R, C, T> result;

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat(i,j) /= val;
        }
    }
    return result;
}

template<size_t N, typename T>
void operator*=(const matrix<N, N, T> &mat1, const matrix<N, N, T> &mat2) {
    matrix<N, N, T> temp(mat1);

    multiply(temp, mat2, mat1);
}

template<size_t R, size_t C, typename T>
void operator+=(matrix<R, C, T> &mat, T &val) {

    matrix<R, C, T> result;
    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat(i,j) +=  val;
        }
    }
}

template<size_t R, size_t C, typename T>
void operator+=(const matrix<R, C, T> &mat1, const matrix<R, C, T> &mat2) {

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat1(i,j) +=  mat2(i,j);
        }
    }
}

template<size_t R, size_t C, typename T>
void operator-(const matrix<R, C, T> &mat, T &val) {

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat(i,j) -=  val;
        }
    }
}

template<size_t R, size_t C, typename T>
void operator-=(const matrix<R, C, T> &mat1, const matrix<R, C, T> &mat2) {

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            mat1(i,j) -=  mat2(i,j);
        }
    }
}

template<size_t R, size_t C, typename T>
matrix<C, R, T> transpose(const matrix<R, C, T> &mat) {

    matrix<C, R, T>result;
    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(j,i) =  mat(i,j);
        }
    }
}

template<size_t R, size_t C, typename T>
vector<C, T> operator*(const matrix<R, C, T> &mat, const vector<C, T> &v) {
    vector<C, T> result(T(0));

    for(size_t i=0; i<R; i++) {
        for(size_t j=0; j<C; j++) {
            result(i) +=  mat(i,j)*v(j);
        }
    }
    return result;
}


