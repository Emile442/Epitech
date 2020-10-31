/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** rrr
*/

#include "my.h"

int ad(int a, int b);
int so(int a, int b);
int mu(int a, int b);
int di(int a, int b);
int mo(int a, int b);

struct ope
{
    char c;
    int (*fct)(int, int);
};

void calcul(int n1, char sign, int n2, struct ope os[6])
{
    if (!n1 && !n2)
        my_putchar(':');
    for(int i = 0; os[i].c ; i++) {
        if (sign == os[i].c) {
            my_putchar(sign);
            my_putchar(':');
            my_putchar(os[i].c);
        }
    }
}

int main(int argc, char const **argv)
{
    struct ope os[6] = {{'+', ad}, {'-', so}, {'*', mu}, {'/', di}, {'%', mo}};
    int n1 = 0;
    int n2 = 0;
    char sign;
    int i;

    if (!argc)
        return 84;
    if (argc < 4)
        return (84);
    else if (argv[2] == 0) {
        my_putchar(48);
        return (84);
    }
    for(i = 0; argv[2][i] && (argv[2][i] != '-' || argv[2][i] != '+' || argv[2][i] != '%' || argv[2][i] != 42 || argv[2][i] != '/'); i++);
    sign = argv[2][i - 1];
    n2 = my_getnbr(argv[1]);
    n1 = my_getnbr(argv[3]);
    if (!n1 && !n2)
        return (84);
    if (!sign)
        return (84);
    if ((argv[1][0] < 48 || argv[1][0] > 57) || argv[1][0] == '-')
        n1 = 0;
    if ((argv[3][0] < 48 || argv[3][0] > 57) || argv[3][0] == '-')
        n2 = 0;
    calcul(n1, sign, n2, os);
    return (0);
}

