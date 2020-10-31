/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex11
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char* tmp;

    if (!this || !this->str || !str)
        return;
    pos = (pos > strlen(this->str)) ? strlen(this->str) : pos;
    tmp = malloc(sizeof(char) * strlen(this->str) + strlen(str) + 1);
    if (!tmp)
        return;
    strncpy(tmp, this->str, pos);
    strcat(tmp, str);
    strcat(tmp, this->str + pos);
    free(this->str);
    this->str = tmp;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (!this || !this->str || !str || !str->str)
        return;
    return (insert_c(this, pos, str->str));
}