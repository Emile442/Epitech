/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04.cpp
*/

#include "ex04.hpp"

template<typename T> bool equal(const T& a, const T& b)
{
    return (a == b);
}

template<typename X> bool Tester<X>::equal(const X& a, const X& b)
{
    return (a == b);
}

template bool equal<int>(const int& a, const int& b);
template bool equal<float>(const float& a, const float& b);
template bool equal<double>(const double& a, const double& b);
template bool equal<std::string>(const std::string& a, const std::string& b);

template bool Tester<int>::equal(const int& a, const int& b);
template bool Tester<float>::equal(const float& a, const float& b);
template bool Tester<double >::equal(const double& a, const double& b);
template bool Tester<std::string >::equal(const std::string& a, const std::string& b);

// int main()
// {
//     std::cout << "1 == 0 ? " << equal(1, 0) << std::endl;
//     std::cout << "1 == 1 ? " << equal(1, 1) << std::endl;
//     Tester<int> iT;
//     std::cout << "41 == 42 ? " << iT.equal(41, 42) << std::endl;
//     std::cout << "42 == 42 ? " << iT.equal(42, 42) << std::endl;
//     return (0);
// }