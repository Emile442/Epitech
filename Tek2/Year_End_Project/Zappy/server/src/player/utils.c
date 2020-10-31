/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** player utils
*/

#include "player.h"

int player_size(player_t *list)
{
    int rt = 0;

    if (list == NULL)
        return (rt);
    for (player_t* tmp = list; tmp; tmp = tmp->next)
        rt++;
    return (rt);
}
