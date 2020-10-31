/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex12
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return (0);
    return (atoi(this->str));
}