/*
** EPITECH PROJECT, 2019
** my strcmp
** File description:
** compares strings
*/

#include "my.h"

bool my_strcmp(char const *str, char const *str2)
{
    for (int i = 0; str[i] || str2[i]; i++)
        if (str[i] != str2[i])
            return (false);
    return (true);
}
