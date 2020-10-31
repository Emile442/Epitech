/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!dest)
        return (NULL);
    dest = my_strcpy(dest, str);
    return (dest);
}
