/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** is nbr neg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
        my_putchar('\n');
        return (-1);
    }
    my_putchar('P');
    my_putchar('\n');
    return (0);
}
