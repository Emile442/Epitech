/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** cursor/default
*/

#include "my_defender.h"

void cursor_to_default(window_t* current)
{
    current->click = &default_click;
    current->cursor = current->default_cursor;
    current->cursor_size = 128;
    current->click_action = 0;
}
