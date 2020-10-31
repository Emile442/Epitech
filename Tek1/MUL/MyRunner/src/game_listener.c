/*
** EPITECH PROJECT, 2018
** game_listener
** File description:
** Game Listener
*/

#include "my_runner.h"
#include "my.h"



void event_listener(window_t *current)
{
    while (sfRenderWindow_pollEvent(current->window, &current->event)) {
        if (current->event.type == sfEvtClosed)
            sfRenderWindow_close(current->window);
        player_listener(current);
    }
}
