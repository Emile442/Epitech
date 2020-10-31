/*
** EPITECH PROJECT, 2018
** clock_init
** File description:
** Clock init
*/

#include "my.h"
#include "my_runner.h"

void init_clock(window_t *current)
{
    current->clock_list = malloc(sizeof(clock_list_t));
    current->clock_list->player = sfClock_create();
    current->clock_list->pr_ground = sfClock_create();
    current->clock_list->pr_midground = sfClock_create();
    current->clock_list->pr_foreground = sfClock_create();
    current->clock_list->score = sfClock_create();
    current->clock_list->pumkin = sfClock_create();
}
