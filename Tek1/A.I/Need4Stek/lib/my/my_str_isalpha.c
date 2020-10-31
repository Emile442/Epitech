/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** is str only alpha
*/

#include "my.h"

bool is_alpha(char c)
{
    if (c > 122 || (c < 97 && c > 90)
        || c < 65)
        return (false);
    return (true);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (is_alpha(str[i]) == false)
            return (0);
    }
    return (1);
}
