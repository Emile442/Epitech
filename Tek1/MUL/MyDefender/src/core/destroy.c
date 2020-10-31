/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** core/destroy
*/

#include "my_defender.h"

void cursor_destroy(sprite_texture_t* cursor);
void scene_destroy(scene_t* scenes);

void destroy(window_t* current)
{
    cursor_destroy(current->cursor);
    scene_destroy(current->scenes);
    destroy_music(current->music_click);
    sfRenderWindow_destroy(current->window);
    free(current->buffer);
    free(current);
}
