/*
** EPITECH PROJECT, 2018
** put_nbr
** File description:
** put_nbr
*/

#include <unistd.h>

void print_nbr(int nb, int min)
{
    int mod = 1000000000;
    int copy = nb;
    char print = 0;

    for (int i = 0; mod != 0; copy = nb, mod /= 10) {
        if ((copy = copy / mod) != 0 || i == 1) {
            print = copy + '0';
            write(1, &print, 1);
            nb = nb % mod;
            i = 1;
        }
        if (min == 1 && i == 1) {
            nb++;
            min = 0;
        }
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        write(1, "-", 1);
        if (nb < 0) {
            nb--;
            print_nbr(nb, 1);
            return (0);
        }
    }
    if (nb == 0)
        write(1, "0", 1);
    print_nbr(nb, 0);
    return (0);
}
