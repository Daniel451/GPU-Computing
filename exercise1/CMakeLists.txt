set(CMAKE_C_COMPILER gcc-4.9)
set(CMAKE_CXX_COMPILER g++-4.9)

cmake_minimum_required(VERSION 3.1)

project(exercise1)

set(SOURCE_FILES main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(exercise1 ${SOURCE_FILES})