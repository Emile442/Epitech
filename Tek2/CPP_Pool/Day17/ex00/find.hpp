/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename X>
typename X::iterator do_find(X &container, int value)
{
    return (std::find(container.begin(), container.end(), value));
}

#endif /* !FIND_HPP_ */
