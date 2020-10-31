/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex09
*/

#include "string.h"

int empty(const string_t *this)
{
    return ((this && ((this->str && this->str[0] == '\0') || \
    !this->str)) ? 1 : 0);
}
