/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** main
*/

#include "n4s.h"

int main(int ac, char **av)
{
    s_n4s *n4s = malloc(sizeof(s_n4s));

    if (n4s == NULL)
        return (84);
    if (main_loop(n4s) == 84) {
        free(n4s);
        return (84);
    }
    free(n4s);
    return (0);
}
