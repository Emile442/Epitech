/*
** EPITECH PROJECT, 2018
** maths_utils
** File description:
** Maths Utils
*/

#include <stdlib.h>
#include <stdbool.h>

#include "my.h"
#include "my_hunter.h"

bool is_in_range(int a, int b, int value)
{
    if (value >= a && value <= b)
        return (true);
    return (false);
}

int static int_len(int nb)
{
    int size = 1;

    while (nb != 0) {
        nb = nb /10;
        size++;
    }
    return (size + 1);
}

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
