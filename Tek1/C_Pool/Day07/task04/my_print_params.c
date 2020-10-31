/*
** EPITECH PROJECT, 2018
** my_print_params
** File description:
** Print Params
*/

#include "../include/my.h"

void my_print_params(int argc, const char **args)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(args[i]);
        my_putchar('\n');
    }
}

int main(int argc, char const **argv)
{
    my_print_params(argc, argv);
    return (0);
}