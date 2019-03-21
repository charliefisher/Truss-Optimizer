cmake_minimum_required(VERSION 3.13)
project(Truss_Optimizer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Truss_Optimizer
        main.cpp
        Truss.cpp
        Truss.hpp)
