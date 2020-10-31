/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Allocates memory an copies string
*/

#include "include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str = NULL;

    str = malloc(sizeof(char *) * my_strlen(src));
    for (int i = 0; src[i]; i++)
        str[i] = src[i];
    return (str);
}