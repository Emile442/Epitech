/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copy n char into another string
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    if (my_strlen(src) > n)
        dest[i] = '\0';
    return (dest);
}
