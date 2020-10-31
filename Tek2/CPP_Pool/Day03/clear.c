/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex04
*/

#include "string.h"

void clear(string_t *this)
{
    if (!this || !this->str)
        return;
    memset(this->str, 0, 1);
}
