cmake_minimum_required(VERSION 2.8)

project(FIRST_PATTERN)

set(CMAKE_CXX_STANDART 14)

set(PROJECT_EXE_SOURCE unit_type.h unit_type.cpp unit.h unit.cpp)

add_executable(PATTERN ${PROJECT_EXE_SOURCE})
