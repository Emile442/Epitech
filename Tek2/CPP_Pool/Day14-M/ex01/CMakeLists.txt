cmake_minimum_required(VERSION 3.15)
project(ex01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex01
        Banana.cpp
        Banana.hpp
        Fruit.cpp
        Fruit.hpp
        FruitBox.cpp
        FruitBox.hpp
        FruitNode.hpp
        Lemon.cpp
        Lemon.hpp
        main.cpp LittleHand.cpp LittleHand.hpp Lime.cpp Lime.hpp)
