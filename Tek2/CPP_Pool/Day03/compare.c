/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex05
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this || !this->str || !str || !str->str)
        return (-1);
    return (compare_c(this, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return (-1);
    return (strcmp(this->str, str));
}
