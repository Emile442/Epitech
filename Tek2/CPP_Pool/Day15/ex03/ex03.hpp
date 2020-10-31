/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex03.hpp
*/

#ifndef CPP_D15_2019_EX03_HPP
#define CPP_D15_2019_EX03_HPP

#include <iostream>

template<typename X> void foreach(const X* array, void (func)(const X &), const int size)
{
    for (int i = 0; i != size; i++)
        func(array[i]);
}

template<typename X> void print(const X & val)
{
    std::cout << val << std::endl;
}
#endif //CPP_D15_2019_EX03_HPP
