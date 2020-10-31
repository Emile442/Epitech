/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
    game_t* game = NULL;
    int status = 0;

    if (ac != 3 || my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 99 \
        || my_getnbr(av[2]) < 1)
        return (EPI_FAILURE);
    game = game_new(av);
    status = matchstick(game);
    return (status);
}
