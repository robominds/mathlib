
cmake_minimum_required(VERSION 4.2)

project(MathLib)

add_library(MathLib INTERFACE)

target_sources(MathLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_include_directories(MathLib INTERFACE include/)


