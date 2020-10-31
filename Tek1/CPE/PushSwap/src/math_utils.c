/*
** EPITECH PROJECT, 2018
** math_utils
** File description:
** math_utils
*/

#include "my.h"

char *int_to_str(int nb)
{
    int size = int_len(nb);
    char *str = malloc(sizeof(char) * size);
    str[size] = '\0';

    if (nb == 0)
        return ("0");
    for (int i = 0; nb != 0; i++) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (my_revstr(str));
}