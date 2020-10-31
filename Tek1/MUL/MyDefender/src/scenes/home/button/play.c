/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button/play
*/

#include "my_defender.h"

void home_play_button_event(window_t* current)
{
    home_t* home = current->scenes->home;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(home->play, mouse)) {
        home->play->callback(current);
        sfRectangleShape_setTexture(home->play->rect, \
        home->play->txt_clicked, sfTrue);
    }
    if (button_is_clicked(home->play, mouse))
        sfRectangleShape_setTexture(home->play->rect, \
        home->play->txt_hover, sfTrue);
    else
        sfRectangleShape_setTexture(home->play->rect, \
        home->play->texture, sfTrue);
}

void home_play_button_draw(window_t* current)
{
    home_t* home = current->scenes->home;

    home_play_button_event(current);
    sfRenderWindow_drawRectangleShape(current->window, home->play->rect, NULL);
}

void home_play_button_destroy(button_t* play)
{
    sfTexture_destroy(play->txt_clicked);
    sfTexture_destroy(play->txt_hover);
    button_destroy(play);
    free(play);
}

void home_play_button_callback(window_t* current)
{
    current->scenes->draw = &game_draw;
    sfMusic_play(current->scenes->game->music);
}

button_t* init_play_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &home_play_button_callback;
    button_init(button, (sfVector2f){665, 400}, (sfVector2f){594, 124}, \
    "assets/img/button_play.png");
    button->txt_hover = sfTexture_createFromFile(\
    "assets/img/button_play_hover.png", NULL);
    button->txt_clicked = sfTexture_createFromFile(\
    "assets/img/button_play_clicked.png", NULL);
    return (button);
}
