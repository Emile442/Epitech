/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex07
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;
    size_t len;

    if (!this || !s || !this->str)
        return (0);
    for (len = strlen(this->str); (pos + i) < len && i < n; i++)
        s[i] = this->str[pos + i];
    if (n > strlen(s))
        s[i++] = 0;
    return (i);
}
