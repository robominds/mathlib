
#pragma once

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <initializer_list>
#include <string.h>

template<size_t R, size_t C, typename T>
class matrix {

  public:  
    matrix(void);
    matrix(T val);
    matrix(const T *vals, size_t numVals, bool colMajor = false);
    matrix(const std::initializer_list<T> list, bool colMajor = false);
    matrix(const matrix<R, C, T> &mat);

    template<typename U>
      explicit matrix(const matrix<R, C, U> &mat);

    inline T& operator()(size_t rowIndx, size_t colIndex);
    inline const T& operator()(size_t rowIndx, size_t colIndex) const;

  private:
    T data[C*R];
};

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(void) {

  memset(data, 0, R*C);
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(T val) {

  memset(data, val, R*C);
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const T *val, size_t numVals, bool colMajor) {

  assert(R*C == numVals);

  if(colMajor) {
    for(int j=0; j<C; j++) {
      for(int i=0; i<R; i++) {
        (*this)(i,j) = *(val++);
      }
    }
  } else {
    for(size_t i=0; i<R*C; i++) {
      data[i] = *(val++); 
    }
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const std::initializer_list<T> list, bool colMajor) {
  const T* iterator = list.begin();

  assert(R*C == list.size());

  if(colMajor) {
    for(int j=0; j<C; j++) {
      for(int i=0; i<R; i++) {
        (*this)(i,j) = *(iterator++);
      }
    }
  } else {
    for(size_t i=0; i<R*C; i++) {
      data[i] = *(iterator++); 
    }
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const matrix<R, C, T> &mat) {

  for(int i=0; i<R*C; i++) {
    data[i] = mat.data[i];
  }
}

template<size_t R, size_t C, typename T>
template<typename U>
matrix<R, C, T>::matrix(const matrix<R, C, U> &mat) {

  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      (*this)(i,j) = static_cast<T>(mat(i,j));
    }
  }
}

template<size_t R, size_t C, typename T>
inline T& matrix<R, C, T>::operator()(size_t rowIndx, size_t colIndx) {

  return data[rowIndx*C+colIndx]; 
}

template<size_t R, size_t C, typename T>
inline const T& matrix<R, C, T>::operator()(size_t rowIndx, size_t colIndx) const {

  return data[rowIndx*C+colIndx]; 
}
