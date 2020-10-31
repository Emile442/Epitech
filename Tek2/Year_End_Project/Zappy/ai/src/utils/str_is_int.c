/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** str_is_int
*/

#include "zappy_ai.h"
#include <ctype.h>

bool str_is_int(char* str)
{
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}
