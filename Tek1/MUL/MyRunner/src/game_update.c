/*
** EPITECH PROJECT, 2018
** game_update
** File description:
** Game Update
*/

#include "my.h"
#include "my_runner.h"

int update_frame(window_t *current)
{
    parallax_draw(current);
    box_colision(current);
    box_draw(current);
    score_draw(current);
    player_draw(current);
    return (0);
}
