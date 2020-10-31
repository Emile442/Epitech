/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button/quit
*/

#include "my_defender.h"

void home_quit_button_event(window_t* current)
{
    home_t* home = current->scenes->home;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(home->quit, mouse)) {
        home->quit->callback(current);
        sfRectangleShape_setTexture(home->quit->rect, \
        home->quit->txt_clicked, sfTrue);
    }
    if (button_is_clicked(home->quit, mouse))
        sfRectangleShape_setTexture(home->quit->rect, \
        home->quit->txt_hover, sfTrue);
    else
        sfRectangleShape_setTexture(home->quit->rect, \
        home->quit->texture, sfTrue);
}

void home_quit_button_draw(window_t* current)
{
    home_t* home = current->scenes->home;

    home_quit_button_event(current);
    sfRenderWindow_drawRectangleShape(current->window, home->quit->rect, NULL);
}

void home_quit_button_destroy(button_t* quit)
{
    sfTexture_destroy(quit->txt_clicked);
    sfTexture_destroy(quit->txt_hover);
    button_destroy(quit);
    free(quit);
}

void home_quit_button_callback(window_t* current)
{
    current->exit = true;
}

button_t* home_init_quit_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &home_quit_button_callback;
    button_init(button, (sfVector2f){665, 585}, (sfVector2f){594, 124}, \
    "assets/img/button_quit.png");
    button->txt_hover = sfTexture_createFromFile(\
    "assets/img/button_quit_hover.png", NULL);
    button->txt_clicked = sfTexture_createFromFile(\
    "assets/img/button_quit_clicked.png", NULL);
    return (button);
}
