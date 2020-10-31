/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex02.hpp
*/

#ifndef CPP_D15_2019_EX02_HPP
#define CPP_D15_2019_EX02_HPP

#include <iostream>

template<class X> X min(const X &a, const X &b)
{
    std::cout << "template min" << std::endl;
    return (a <= b ? a : b);
}

int min(const int a, const int b)
{
    std::cout << "non-template min" << std::endl;
    return (a <= b ? a : b);
}

template<class X> const X templateMin(const X* array, const int size)
{
    X tmp = array[0];

    for (int i = 0; i != size - 1; i++)
        tmp = min<X>(tmp, array[i + 1]);
    return (tmp);
}

int nonTemplateMin(const int* array, const int size)
{
    int tmp = array[0];
    for (int i = 0; i != size - 1; i++)
        tmp = min(tmp, array[i + 1]);
    return (tmp);
}



#endif //CPP_D15_2019_EX02_HPP
