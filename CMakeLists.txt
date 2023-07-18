cmake_minimum_required(VERSION 3.25)
project(learncpp_monster_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(learncpp_monster_game src/main.cpp src/Creature.cpp src/Creature.hpp src/Player.cpp src/Player.hpp src/Monster.cpp src/Monster.hpp src/RandomIntGenerator.cpp src/RandomIntGenerator.hpp)
