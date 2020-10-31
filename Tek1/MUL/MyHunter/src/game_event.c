/*
** EPITECH PROJECT, 2018
** game_event
** File description:
** Game event
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#include "my_hunter.h"
#include "my.h"

void event_listener(window_t *current)
{
    while (sfRenderWindow_pollEvent(current->window, &current->event)) {
        if (current->event.type == sfEvtClosed)
            sfRenderWindow_close(current->window);
        if (!current->lives)
            current->status = 2;
        bird_dead_listener(current);
        game_lister(current);
    }
}

void end_game_lister(window_t *current)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed \
    && current->status == 2) {
        if (is_in_range((1920 / 2) - (482 / 2), (1920 / 2) + (482 / 2), \
        mouse_pos.x) && is_in_range(550, 550 + 169, mouse_pos.y)) {
            sfRenderWindow_close(current->window);
        }
    }
    if (current->event.type == sfEvtMouseButtonPressed \
    && current->status == 2) {
        if (is_in_range((1920 / 2) - (482 / 2), (1920 / 2) + (482 / 2), \
        mouse_pos.x) && is_in_range(350, 350 + 169, mouse_pos.y)) {
            current->score = 0;
            current->lives = 3;
            current->status = 1;
            sfText_setString(current->scoreboard->text, \
            int_to_str(current->score));
            reset_bird(current);
        }
    }
}

void game_lister(window_t *current)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed \
    && current->status == 0) {
        if (is_in_range((1920 / 2) - (482 / 2), (1920 / 2) + (482 / 2), \
        mouse_pos.x) && is_in_range((1080 / 2) - (169 / 2), \
        (1080 / 2) + (169 / 2), mouse_pos.y)) {
            current->status = 1;
            reset_bird(current);
        }
    }
    end_game_lister(current);
}