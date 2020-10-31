/*
** EPITECH PROJECT, 2018
** my_rev_params
** File description:
** Print paramas in reverse order
*/

#include "../include/my.h"

void my_rev_params(int argc, const char **args)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(args[i]);
        my_putchar('\n');
    }
}

int main(int argc, char const **argv)
{
    my_rev_params(argc, argv);
    return (0);
}