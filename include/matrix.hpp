
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

    matrix<R, C, T>& operator=(const matrix<R, C, T> &other);

    inline T& operator()(size_t rowIndx, size_t colIndex);
    inline const T& operator()(size_t rowIndx, size_t colIndex) const;

  private:
    T data[C*R];
};

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(void) {

  memset(data, 0, R * C * sizeof(T));
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(T val) {

  for(size_t i = 0; i < R * C; i++) {
    data[i] = val;
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const T *val, size_t numVals, bool colMajor) {

  assert(R*C == numVals);

  if(colMajor) {
    for(size_t j = 0; j < C; j++) {
      for(size_t i = 0; i < R; i++) {
        (*this)(i,j) = *(val++);
      }
    }
  } else {
    for(size_t i = 0; i < R*C; i++) {
      data[i] = *(val++); 
    }
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const std::initializer_list<T> list, bool colMajor) {
  const T* iterator = list.begin();

  assert(R*C == list.size());

  if(colMajor) {
    for(size_t j = 0; j < C; j++) {
      for(size_t i = 0; i < R; i++) {
        (*this)(i,j) = *(iterator++);
      }
    }
  } else {
    for(size_t i = 0; i < R*C; i++) {
      data[i] = *(iterator++); 
    }
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>::matrix(const matrix<R, C, T> &mat) {

  for(size_t i = 0; i < R * C; i++) {
    data[i] = mat.data[i];
  }
}

template<size_t R, size_t C, typename T>
template<typename U>
matrix<R, C, T>::matrix(const matrix<R, C, U> &mat) {

  for(size_t i = 0; i < R; i++) {
    for(size_t j = 0; j < C; j++) {
      (*this)(i,j) = static_cast<T>(mat(i,j));
    }
  }
}

template<size_t R, size_t C, typename T>
matrix<R, C, T>& matrix<R, C, T>::operator=(const matrix<R, C, T> &other) {
  if(this != &other) {
    for(size_t i = 0; i < R * C; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

template<size_t R, size_t C, typename T>
inline T& matrix<R, C, T>::operator()(size_t rowIndx, size_t colIndx) {
  assert(rowIndx < R && colIndx < C);
  return data[rowIndx*C+colIndx]; 
}

template<size_t R, size_t C, typename T>
inline const T& matrix<R, C, T>::operator()(size_t rowIndx, size_t colIndx) const {
  assert(rowIndx < R && colIndx < C);
  return data[rowIndx*C+colIndx]; 
}
