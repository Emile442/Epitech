/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concate two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int d = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++, d++)
        dest[d] = src[i];
    dest[d] = '\0';
    return (dest);
}
