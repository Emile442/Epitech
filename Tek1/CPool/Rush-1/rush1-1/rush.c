/*
** EPITECH PROJECT, 2018
** rush1-1
** File description:
** Square
*/
#include <unistd.h>

void my_putchar(char c);

void top(int x, char side[], char fill[])
{
    int x_tmp = x;
    for (; x != 0; x--) {
        if (x == x_tmp)
            my_putchar(side[0]);
        else if (x == 1)
            my_putchar(side[1]);
        else
            my_putchar(fill[0]);
    }
    my_putchar('\n');
}

void bot(int x, char side[], char fill[])
{
    int x_tmp = x;
    for (; x != 0; x--) {
        if (x == x_tmp)
            my_putchar(side[2]);
        else if (x == 1)
            my_putchar(side[3]);
        else
            my_putchar(fill[0]);
    }
    my_putchar('\n');
}

void mid(int x, char fill[])
{
    int x_tmp = x;
    for (; x != 0; x--) {
        if (x == x_tmp)
            my_putchar(fill[1]);
        else if (x == 1)
            my_putchar(fill[1]);
        else
            my_putchar(' ');
    }
    my_putchar('\n');
}

int rush(int x, int y)
{
    char side[] = {'o', 'o', 'o', 'o'};
    char fill[] = {'-', '|'};

    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return (0);
    }
    top(x, side, fill);
    if (y == 1)
        return (0);
    for (int tmp = y - 2; tmp != 0; tmp--)
        mid(x, fill);
    bot(x, side, fill);
    return (0);
}