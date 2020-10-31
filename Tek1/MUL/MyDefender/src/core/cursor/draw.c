/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** cursor/draw.c
*/

#include "my_defender.h"

void cursor_draw(window_t* current)
{
    sfVector2i mouse_pos;
    sfVector2f scope_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(current->window);
    scope_pos.x = mouse_pos.x - (current->cursor_size / 2);
    scope_pos.y = mouse_pos.y - (current->cursor_size / 2);
    sfSprite_setPosition(current->cursor->sprite, scope_pos);
    sfRenderWindow_drawSprite(current->window, current->cursor->sprite, NULL);
}
