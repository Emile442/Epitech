/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** RFC Str
*/

#include "zappy_ai.h"

char* format_str(char* str)
{
    char* rt = calloc(strlen(str) + 2, sizeof(char));

    sprintf(rt, "%s\n", str);
    return (rt);
}
