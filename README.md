# MathLib

A header-only C++ template library for vectors, matrices, and quaternions.

## Features

- **Vectors**: Fixed-size vector templates with common operations (dot product, cross product, normalization)
- **Matrices**: Fixed-size matrix templates with arithmetic operations and linear algebra functions
- **Quaternions**: Quaternion class for rotation representation and manipulation
- **Type-safe**: Compile-time size checking with template parameters
- **Performance**: Inline operations and stack-allocated data for efficiency

## Usage

### Vectors

```cpp
#include "vector.hpp"
#include "vectorMath.hpp"

// Create vectors
vector<3, float> v1 = {1.0f, 2.0f, 3.0f};
vector<3, float> v2{4.0f, 5.0f, 6.0f};

// Vector operations
float dotProduct = dot(v1, v2);
vector<3, float> crossProduct = cross(v1, v2);
vector<3, float> v3 = v1 + v2;
vector<3, float> normalized = normalize(v1);
```

### Matrices

```cpp
#include "matrix.hpp"
#include "matrixMath.hpp"

// Create matrices
matrix<3, 3, float> m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
matrix<3, 3, float> identity = eye<3, float>();

// Matrix operations
matrix<3, 3, float> m2 = m1 * identity;
matrix<3, 3, float> m3 = transpose(m1);

// Matrix-vector multiplication
vector<3, float> v = {1.0f, 2.0f, 3.0f};
vector<3, float> result = m1 * v;
```

### Quaternions

```cpp
#include "quaternion.hpp"

// Create quaternions
quaternion<float> q1;  // Identity quaternion
quaternion<float> q2({0.0f, 1.0f, 0.0f, 0.0f});  // Pure quaternion
```

## Requirements

- C++17 or later
- CMake 3.15+

## Building

```bash
mkdir build
cd build
cmake ..
make
```
