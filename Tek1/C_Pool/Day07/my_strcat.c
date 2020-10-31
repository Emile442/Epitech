/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenates two strings
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = 0;

    for (; dest[len] != 0; len++);
    for (int i = 0; src[i] != 0; i++) {
        dest[len] = src[i];
        len++;
    }
    dest[len] = 0;
    return dest;
}