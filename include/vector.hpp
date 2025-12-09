
#pragma once

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <initializer_list>
#include <string.h>

template<size_t N, typename T>
class vector {

  public:  
    vector(void);
    vector(T val);
    vector(const T *vals, size_t numVals);
    vector(const std::initializer_list<T> list);
    vector(const vector<N, T> &val);

    template<typename U>
      explicit vector(const vector<N, U> &vec);

    inline T& operator()(size_t indx);
    inline const T& operator()(size_t indx) const;

  private:
    T data[N];
};


template<size_t N, typename T>
vector<N, T>::vector(void) {

  memset(data, 0, N);
}

template<size_t N, typename T>
vector<N, T>::vector(const T val) {

  memset(data, val, N);
}

template<size_t N, typename T>
vector<N, T>::vector(const T *val, size_t numVals) {
  int k=0;

  for(int i=0; i<N; i++) {
    data(i) = val[i];
  }
}

template<size_t N, typename T>
vector<N, T>::vector(const std::initializer_list<T> list) {
  const T* iterator = list.begin();

  assert(N == list.size());

  for(size_t i=0; i<N; i++) {
    data[i] = *(iterator++);
  }
}

template<size_t N, typename T>
vector<N, T>::vector(const vector<N, T> &mat) {

  for(int i=0; i<N; i++) data[i] = mat.data[i];
}

template<size_t N, typename T>
template<typename U>
vector<N, T>::vector(const vector<N, U> &mat) {

  for(int i=0; i<N; i++) {
    data(i) = (T)mat(i);
  }
}

template<size_t N, typename T>
inline T& vector<N, T>::operator()(size_t indx) {

  return data[indx]; 
}

template<size_t N, typename T>
inline const T& vector<N, T>::operator()(size_t indx) const {

  return data[indx]; 
}
