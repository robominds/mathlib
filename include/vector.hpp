
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

    vector<N, T>& operator=(const vector<N, T> &other);

    inline T& operator()(size_t indx);
    inline const T& operator()(size_t indx) const;

  private:
    T data[N];
};


template<size_t N, typename T>
vector<N, T>::vector(void) {

  memset(data, 0, N * sizeof(T));
}

template<size_t N, typename T>
vector<N, T>::vector(const T val) {

  for(size_t i = 0; i < N; i++) {
    data[i] = val;
  }
}

template<size_t N, typename T>
vector<N, T>::vector(const T *val, size_t numVals) {
  assert(N == numVals);

  for(size_t i = 0; i < N; i++) {
    data[i] = val[i];
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

  for(size_t i = 0; i < N; i++) data[i] = mat.data[i];
}

template<size_t N, typename T>
template<typename U>
vector<N, T>::vector(const vector<N, U> &mat) {

  for(size_t i = 0; i < N; i++) {
    data[i] = static_cast<T>(mat(i));
  }
}

template<size_t N, typename T>
vector<N, T>& vector<N, T>::operator=(const vector<N, T> &other) {
  if(this != &other) {
    for(size_t i = 0; i < N; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
}

template<size_t N, typename T>
inline T& vector<N, T>::operator()(size_t indx) {
  assert(indx < N);
  return data[indx]; 
}

template<size_t N, typename T>
inline const T& vector<N, T>::operator()(size_t indx) const {
  assert(indx < N);
  return data[indx]; 
}
