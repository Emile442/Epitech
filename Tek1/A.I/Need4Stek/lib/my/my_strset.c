/*
** EPITECH PROJECT, 2018
** my_memset.c
** File description:
** my_memset
*/

#include "my.h"

char *my_strset(int size, char c)
{
    char *str = malloc(sizeof(char) * size);
    int i = 0;

    if (!str)
        return (NULL);
    for (; i < size - 1; i++)
        str[i] = c;
    str[i] = '\0';
    return (str);
}
