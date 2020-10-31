/*
** EPITECH PROJECT, 2018
** score_update
** File description:
** Score Update
*/

#include "my.h"
#include "my_runner.h"

void score_update(window_t *current)
{
    sfClock_restart(current->clock_list->score);
    current->scoreboard->value++;
    sfText_setString(current->scoreboard->text, \
    int_to_str(current->scoreboard->value));
}
