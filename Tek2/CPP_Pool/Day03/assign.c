/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex01
*/

#include "string.h"

void assign_s(string_t *this , const string_t *str)
{
    return (assign_c(this, str->str));
}

void assign_c(string_t *this, const char *s)
{
    if (!s)
        return;
    string_destroy(this);
    this->str = strdup(s);
}
