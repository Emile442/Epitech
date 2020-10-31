cmake_minimum_required(VERSION 3.15)
project(ex01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex01
        AEnemy.cpp
        AEnemy.hpp
        AWeapon.cpp
        AWeapon.hpp
        Character.cpp
        Character.hpp
        PlasmaRifle.cpp
        PlasmaRifle.hpp
        PowerFist.cpp
        PowerFist.hpp
        RadScorpion.cpp
        RadScorpion.hpp
        SuperMutant.cpp
        SuperMutant.hpp
        main.cpp)
