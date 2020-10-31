/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button/resume
*/

#include "my_defender.h"

void pause_resume_button_event(window_t* current)
{
    pause_t* pause = current->scenes->pause;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(current->window);

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(pause->resume, mouse)) {
        pause->resume->callback(current);
        sfRectangleShape_setTexture(pause->resume->rect, \
        pause->resume->txt_clicked, sfTrue);
    }
    if (button_is_clicked(pause->resume, mouse))
        sfRectangleShape_setTexture(pause->resume->rect, \
        pause->resume->txt_hover, sfTrue);
    else
        sfRectangleShape_setTexture(pause->resume->rect, \
        pause->resume->texture, sfTrue);
}

void pause_resume_button_draw(window_t* current)
{
    pause_t* pause = current->scenes->pause;

    pause_resume_button_event(current);
    sfRenderWindow_drawRectangleShape(current->window, pause->resume->rect, \
    NULL);
}

void pause_resume_button_destroy(button_t* resume)
{
    sfTexture_destroy(resume->txt_clicked);
    sfTexture_destroy(resume->txt_hover);
    button_destroy(resume);
    free(resume);
}

void pause_resume_button_callback(window_t* current)
{
    current->scenes->draw = &game_draw;
    sfMusic_play(current->scenes->game->music);
}

button_t* pause_init_resume_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &pause_resume_button_callback;
    button_init(button, (sfVector2f){665, 315}, (sfVector2f){594, 124}, \
    "assets/img/button_resume.png");
    button->txt_hover = sfTexture_createFromFile(\
    "assets/img/button_resume_hover.png", NULL);
    button->txt_clicked = sfTexture_createFromFile(\
    "assets/img/button_resume_clicked.png", NULL);
    return (button);
}
