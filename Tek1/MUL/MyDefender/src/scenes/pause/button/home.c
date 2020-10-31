/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button/home
*/

#include "my_defender.h"

void pause_home_button_event(window_t* current)
{
    pause_t* pause = current->scenes->pause;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(pause->home, mouse)) {
        pause->home->callback(current);
        sfRectangleShape_setTexture(pause->home->rect, \
        pause->home->txt_clicked, sfTrue);
    }
    if (button_is_clicked(pause->home, mouse))
        sfRectangleShape_setTexture(pause->home->rect, \
        pause->home->txt_hover, sfTrue);
    else
        sfRectangleShape_setTexture(pause->home->rect, \
        pause->home->texture, sfTrue);
}

void pause_home_button_draw(window_t* current)
{
    pause_t* pause = current->scenes->pause;

    pause_home_button_event(current);
    sfRenderWindow_drawRectangleShape(current->window, pause->home->rect, NULL);
}

void pause_home_button_destroy(button_t* home)
{
    sfTexture_destroy(home->txt_clicked);
    sfTexture_destroy(home->txt_hover);
    button_destroy(home);
    free(home);
}

void pause_home_button_callback(window_t* current)
{
    game_destroy(current->scenes->game);
    current->scenes->game = game_init();
    current->scenes->draw = &home_draw;
}

button_t* pause_init_home_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &pause_home_button_callback;
    button_init(button, (sfVector2f){665, 490}, (sfVector2f){594, 124}, \
    "assets/img/button_main_menu.png");
    button->txt_hover = sfTexture_createFromFile(\
    "assets/img/button_main_menu_hover.png", NULL);
    button->txt_clicked = sfTexture_createFromFile(\
    "assets/img/button_main_menu_clicked.png", NULL);
    return (button);
}
