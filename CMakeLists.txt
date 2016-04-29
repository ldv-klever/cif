cmake_minimum_required(VERSION 3.5)
project(cif)

set(CMAKE_CXX_COMPILER "/usr/bin/gcc")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cif.c)

add_executable(cif ${SOURCE_FILES})