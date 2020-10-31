/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two strings
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (my_strlen(str1) > my_strlen(str2))
        return (1);
    if (my_strlen(str1) < my_strlen(str2))
        return (-1);
    for (; str1[i]; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (0);
}
