/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** utils/int_to_str
*/

#include "my_defender.h"

static int int_len(int nb)
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

    my_memset(str, '\0', size);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (int i = 0; nb != 0; i++) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (my_revstr(str));
}
