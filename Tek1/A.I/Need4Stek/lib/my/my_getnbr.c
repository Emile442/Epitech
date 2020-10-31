/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get int from str
*/

#include "my.h"

int count_neg(char const *str)
{
    int neg = 0;
    int i = 0;

    while (is_digit(str[i]) != true) {
        if (str[i] == '-')
            neg++;
        i++;
    }
    return (neg);
}

bool is_digit(char c)
{
    if (c < '0' || c > '9')
        return (false);
    return (true);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    for (; str[i] == '-' || str[i] == '+'; i++);
    for (; str[i]; (nbr = nbr * 10 + str[i] - 48), i++) {
        if (is_digit(str[i]) != true && (count_neg(str) % 2) == 0)
            return (nbr);
        if (is_digit(str[i]) == false && (count_neg(str) % 2) == 1)
            return (nbr * -1);
        if (nbr > 214748364 || (nbr == 21478364 && (str[i] == '9'
            || (str[i] == '8' && (count_neg(str) % 2) == 0))))
            return (0);
    }
    if ((count_neg(str) % 2) == 1)
        return (nbr * -1);
    return (nbr);
}
