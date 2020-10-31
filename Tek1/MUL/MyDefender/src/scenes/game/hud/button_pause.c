/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/buttun_pause
*/

#include "my_defender.h"

void pause_button_event(window_t* current)
{
    hud_t* hud = current->scenes->game->hud;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(hud->pause, mouse)) {
        hud->pause->callback(current);
        sfRectangleShape_setTexture(hud->pause->rect, \
        hud->pause->txt_clicked, sfTrue);
    }
    if (button_is_clicked(hud->pause, mouse))
        sfRectangleShape_setTexture(hud->pause->rect, \
        hud->pause->txt_hover, sfTrue);
    else
        sfRectangleShape_setTexture(hud->pause->rect, \
        hud->pause->texture, sfTrue);
}

void pause_button_draw(window_t* current)
{
    hud_t* hud = current->scenes->game->hud;

    pause_button_event(current);
    sfRenderWindow_drawRectangleShape(current->window, hud->pause->rect, NULL);
}

void pause_button_destroy(button_t* pause)
{
    sfTexture_destroy(pause->txt_clicked);
    sfTexture_destroy(pause->txt_hover);
    button_destroy(pause);
    free(pause);
}

void pause_button_callback(window_t* current)
{
    current->scenes->draw = &pause_draw;
    sfMusic_pause(current->scenes->game->music);
}

button_t* init_pause_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &pause_button_callback;
    button_init(button, (sfVector2f){1712, 20}, (sfVector2f){189, 59}, \
    "assets/img/button_pause.png");
    button->txt_hover = sfTexture_createFromFile(\
    "assets/img/button_pause_hover.png", NULL);
    button->txt_clicked = sfTexture_createFromFile(\
    "assets/img/button_pause_clicked.png", NULL);
    return (button);
}
