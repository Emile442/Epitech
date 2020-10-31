/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Allocates memory an copies string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str = NULL;

    str = malloc(sizeof(char *) * my_strlen(src));
    for (int i = 0; src[i]; i++)
        str[i] = src[i];
    return (str);
}