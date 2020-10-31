/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex05
*/

#include "string.h"

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}
