/*
** EPITECH PROJECT, 2018
** my_put_basics
** File description:
** basic write
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int my_putstr(char const *str)
{
    int len;

    len = my_strlen(str);
    write(1, str, len);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}

int my_put_m_str(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
        else {
            char oct[] = "\\000";
            oct[1] = str[i] / 64 + '0';
            oct[2] = (str[i] / 8) % 8 + '0';
            oct[3] = str[i] % 8 + '0';
            my_putstr(oct);
        }
    }
    return (0);
}

//int my_put_ptr(void *ptr) library/lib/verified
