/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex03
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) < pos)
        return (-1);
    return (this->str[pos]);
}
