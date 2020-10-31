/*
** EPITECH PROJECT, 2018
** My Get Nbr
** File description:
** my_get_nbr.c
*/

#include <my.h>

int my_get_nbr(char const *str)
{
    int nb = 0;
    int is_neg = 0;

    if (my_str_isnum(str))
        return (0);
    for (int i = 0; str[i] && str[i] != 10; i++) {
        if (i == 0 && str[i] == '-')
            is_neg = 1;
        else {
            nb *= 10;
            nb += str[i] - '0';
        }
    }
    (is_neg) ? nb *= -1 : 0;
    return (nb);
}
