
cmake_minimum_required(VERSION 3.15)

project(MathLib VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create header-only library
add_library(MathLib INTERFACE)

# Add include directories
target_include_directories(MathLib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set C++ standard for the library
target_compile_features(MathLib INTERFACE cxx_std_17)


