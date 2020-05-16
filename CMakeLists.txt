cmake_minimum_required(VERSION 2.8)

proect(myGame)

set(PROJECT_EXE_SOURCE Horse_Warrior.cpp Infantry_Warrior.cpp Nina_Warrior.cpp Player.cpp Squad.cpp)

add_executable(FULLCODE ${PROJECT_EXE_SOURCE})
