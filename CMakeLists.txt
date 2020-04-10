cmake_minimum_required(VERSION 2.8)


project(FIRST_CHECPOINT_PATTERN)

set(CMAKE_CXX_STANDART 14)

set(PROJECT_EXE_SOURCE Abstract_Factory_Warrior.h Abstract_Factory_Equipment.h Factory_Warrior.cpp Factory_Equipment.cpp)

add_executable(PATTERN ${PROJECT_EXE_SOURCE})
