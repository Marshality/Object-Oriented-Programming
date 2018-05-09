cmake_minimum_required(VERSION 3.10)
project(vtemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(vtemplate main.cpp vector.h _vector.h basevector.h iterator.h)