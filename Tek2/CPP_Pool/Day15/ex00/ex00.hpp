/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex00.hpp
*/

#ifndef CPP_D15_2019_EX00_HPP
#define CPP_D15_2019_EX00_HPP

template<typename X> void swap(X &a, X &b)
{
    X tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename X> const X min(const X &a, const X &b)
{
    return (a <= b ? a : b);
}

template<typename X> const X max(const X &a, const X &b)
{
    return (a >= b ? a : b);
}

template<typename X> X add(const X &a, const X &b)
{
    return (a + b);
}

#endif //CPP_D15_2019_EX00_HPP
