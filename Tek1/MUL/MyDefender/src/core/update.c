/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** update
*/

#include "my_defender.h"

void cursor_draw(window_t* current);

int update_frame(window_t *current)
{
    while (sfRenderWindow_pollEvent(current->window, &current->event)) {
        if (current->event.type == sfEvtClosed)
            sfRenderWindow_close(current->window);
        if (current->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(current->music_click);
            current->click(current);
        }
    }
    sfRenderWindow_clear(current->window, sfBlack);
    current->scenes->draw(current);
    cursor_draw(current);
    sfRenderWindow_display(current->window);
    return (0);
}
