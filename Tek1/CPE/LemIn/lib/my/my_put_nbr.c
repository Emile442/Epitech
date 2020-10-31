/*
** EPITECH PROJECT, 2019
** my put nbr
** File description:
** my put nbr
*/

#include "my.h"

int my_put_nbr_arg(int fd, va_list ap)
{
    return (my_put_nbr(fd, va_arg(ap, int)));
}

int my_put_nbr(int fd, int nbr)
{
    int printed = 0;

    if (nbr < 0) {
        printed += my_putchar(fd, '-');
        return (printed + my_put_nbr(fd, -nbr));
    }
    if (nbr/10 >= 1)
        printed += my_put_nbr(fd, nbr/10);
    return (printed + my_putchar(fd, '0' + nbr % 10));
}
