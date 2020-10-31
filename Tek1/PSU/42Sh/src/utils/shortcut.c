/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** utils
*/

#include "sh.h"

void free_dchar(char** array)
{
    if (!array || !array[0])
        return;
    for (int i = 0; array[i]; free(array[i]), i++);
    free(array);
}

bool str_have(char* str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (true);
    return (false);
}
