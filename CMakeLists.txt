cmake_minimum_required(VERSION 2.8)


project(FIRST_CHECPOINT_PATTERN)

set(CMAKE_CXX_STANDART 17)

set(PROJECT_EXE_SOURCE Abstract_Factory_Warrior_and_Equipment.cpp test.cpp)

add_executable(PATTERN ${PROJECT_EXE_SOURCE})
