cmake_minimum_required(VERSION 3.15)
project(cpp_d09_2019)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_d09_2019
        Character.cpp
        Character.hpp
        Warrior.cpp
        Warrior.hpp
        Mage.cpp
        Mage.hpp
        Priest.cpp
        Priest.hpp)
