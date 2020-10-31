/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex08
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this || !this->str)
        return (NULL);
    return (this->str);
}
