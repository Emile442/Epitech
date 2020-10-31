/*
** EPITECH PROJECT, 2020
** zappy [WSL: Ubuntu-18.04]
** File description:
** check_alphanum
*/

#include "zappy_ai.h"

bool check_alphanum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            return (false);
    return (true);
}