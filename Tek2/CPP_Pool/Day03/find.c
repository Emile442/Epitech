/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex10
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (!this || !this->str || !str || !str->str)
        return (-1);
    return (find_c(this, str->str, pos));
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char* newstr;
    char* tmp;
    int i = pos;

    if (!this || !this->str || !str)
        return (-1);
    if (strlen(str) > strlen(this->str) || pos > strlen(this->str))
        return (-1);
    newstr = strdup(this->str);
    newstr += pos;
    tmp = strstr(newstr, str);
    i += tmp - newstr;
    return (tmp ? i : -1);
}
