cmake_minimum_required(VERSION 3.9)
project(mtemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

add_executable(mtemplate main.cpp basematrix.h matrix.h _matrix.h iterator.h _iterator.h)