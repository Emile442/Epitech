/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** Ex01
*/

#include "menger.h"

bool string_isdigit(char* str)
{
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]) && str[i] != '-')
            return (false);
    }
    return (true);
}

bool has_error(int ac, char** av)
{
    if (ac != 3)
        return (true);
    if (!string_isdigit(av[1]))
        return (true);
    if (!string_isdigit(av[2]))
        return (true);
    if (atoi(av[1]) < 3 || atoi(av[1]) % 3 != 0)
        return (true);
    if (atoi(av[2]) < 1)
        return (true);
    return (false);
}

int main(int ac, char** av)
{
    (void)ac;

    if (has_error(ac, av))
        return (84);
    menger(atoi(av[1]), atoi(av[2]), 0, 0);
    return (0);
}

