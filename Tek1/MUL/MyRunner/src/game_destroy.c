/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Game destroy
*/

#include "my.h"
#include "my_runner.h"

void game_destroy(window_t *current)
{
    score_destroy(current);
    sfMusic_destroy(current->music);
    sfRenderWindow_destroy(current->window);
    free(current->buffer);
    free(current);
}
