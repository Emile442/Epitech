/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** compare n characters
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (my_strlen(s1) - my_strlen(s2));
    for (; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
