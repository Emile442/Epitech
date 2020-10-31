/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** concate two strings
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int d = my_strlen(dest);
    int i = 0;

    for (; i < nb; i++, d++)
        dest[d] = src[i];
    dest[d] = '\0';
    return (dest);
}
