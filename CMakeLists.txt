cmake_minimum_required(VERSION 3.23)
project(Calc)

set(CMAKE_CXX_STANDARD 23)

add_executable(Calc calc.cpp header.hpp task.cpp correct.cpp solve.cpp func.cpp "check and fix.cpp")
