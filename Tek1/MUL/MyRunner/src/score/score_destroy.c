/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Score Destroy
*/

#include "my.h"
#include "my_runner.h"

void score_destroy(window_t *current)
{
    sfText_destroy(current->scoreboard->text);
    sfFont_destroy(current->scoreboard->font);
    free(current->scoreboard);
}
