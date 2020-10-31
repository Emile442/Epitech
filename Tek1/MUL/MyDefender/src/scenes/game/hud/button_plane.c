/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/button_tower
*/

#include "my_defender.h"

void callback_plane_button(window_t* current)
{
    sprite_texture_t* spt = init_spt("assets/img/plane.png");
    sfVector2f btn_pos = sfRectangleShape_getPosition(\
    current->scenes->game->hud->plane->rect);

    current->cursor = spt;
    current->cursor_size = 2;
    current->click = &weapon_add;
    current->click_action = 4;
    current->scenes->game->hud->infos->money->value -= 550;
    sfMouse_setPosition((sfVector2i){btn_pos.x, btn_pos.y}, \
    (sfWindow*)current->window);
}

void event_plane_button(window_t* current)
{
    hud_t* hud = current->scenes->game->hud;

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(hud->plane, \
    sfMouse_getPositionRenderWindow(current->window))) {
        hud->plane->callback(current);
    }
}

void draw_plane_button(window_t* current)
{
    if (!current->scenes->game->delta_charlie->in_progress &&
        current->scenes->game->hud->infos->money->value >= 550)
        event_plane_button(current);
    sfRenderWindow_drawRectangleShape(current->window, \
    current->scenes->game->hud->plane->rect, NULL);
}

button_t* init_plane_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &callback_plane_button;
    button_init(button, (sfVector2f){1154, 925}, (sfVector2f){128, 128}, \
    "assets/img/plane.png");
    return (button);
}
