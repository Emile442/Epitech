cmake_minimum_required(VERSION 3.15)
project(ex00)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(ex00
        Banana.cpp
        Banana.hpp
        Fruit.cpp
        Fruit.hpp
        FruitBox.cpp
        FruitBox.hpp
        FruitNode.hpp
        Lemon.cpp
        Lemon.hpp main.cpp)
