/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex01.hpp
*/

#ifndef CPP_D15_2019_EX01_HPP
#define CPP_D15_2019_EX01_HPP

#include <cstring>

template<const char *> int compare (const char* &str1, const char* &str2)
{
    if (std::strcmp(str1, str2) == 0)
        return (0);
    return (std::strcmp(str1, str2) < 0 ? -1 : 1);
}

template<typename X> int compare(const X &a, const X &b)
{
    if (a == b)
        return (0);
    return (a < b ? -1 : 1);
}


#endif //CPP_D15_2019_EX01_HPP
