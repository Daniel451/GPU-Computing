set(CMAKE_C_COMPILER gcc-4.9)
set(CMAKE_CXX_COMPILER g++-4.9)

cmake_minimum_required(VERSION 3.2)

project(exercise3)

set(SOURCE_FILES main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(exercise3 ${SOURCE_FILES})