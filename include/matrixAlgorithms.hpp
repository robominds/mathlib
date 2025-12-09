
#pragma once

#include "matrixMath.hpp"
#include "stdio.h"

template<size_t R, size_t C, typename T>
T cofactor(const matrix<R, C, T> &mat, size_t row, size_t col);

template<typename T>
T determinant(const matrix<1, 1, T> &mat) {

    return mat(0,0);
}

template<typename T>
T determinant(const matrix<2, 2, T> &mat) {

    return mat(0,0)*mat(1,1)-mat(0,1)*mat(1,0);
}

template<typename T>
T determinant(const matrix<3, 3, T> &mat) {

    return 
        mat(0,0)*mat(1,1)*mat(2,2) +
        mat(0,1)*mat(1,2)*mat(2,0) +
        mat(0,2)*mat(1,0)*mat(2,1) -
        mat(2,0)*mat(1,1)*mat(0,2) -
        mat(2,1)*mat(1,2)*mat(0,0) -
        mat(2,2)*mat(1,0)*mat(0,1);
}

template<size_t R, size_t C, typename T>
T determinant(const matrix<R, C, T> &mat) {
    T result = T(0);

    for(size_t i=0; i<R; i++) {
        result += mat(i,1)*cofactor(mat, i, 1);
    }
    return result;
}

template<size_t R, size_t C, typename T>
T cofactor(const matrix<R, C, T> &mat, size_t row, size_t col) {
    matrix<R-1, C-1, T> subMat;
    size_t ii = 0;
    size_t jj = 0;

    for(size_t i=0; i<R; i++) {
        jj = 0;
        if(i != row) {
            for(size_t j=0; j<C; j++) {
                if(j != col) {
                    subMat(ii,jj) = mat(i,j);
                    jj++;
                }
            }
            ii++;
        }
    }    
    if( (row+col)%2 == 0) {
        return determinant(subMat);
    } else {
        return -determinant(subMat);
    } 
}

template<size_t N, typename T>
matrix<N, N, T> adjoint(const matrix<N, N, T> &mat) {
    matrix<N, N, T> adj;

    for(size_t i=0; i<N; i++) {
        for(size_t j=0; j<N; j++) {
            adj(j,i) = cofactor(mat, i, j);
        }
    }
    return adj;
}

template<size_t N, typename T>
matrix<N, N, T> inverse(const matrix<N, N, T> &mat) {

    matrix<N, N, T> adj = adjoint(mat);
    return adj/determinant(mat);
}
