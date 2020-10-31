/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/button_tower
*/

#include "my_defender.h"

void callback_tower_3_button(window_t* current)
{
    sprite_texture_t* spt = init_spt("assets/img/turret3/turret_3.png");
    sfVector2f btn_pos = sfRectangleShape_getPosition(\
    current->scenes->game->hud->tower_3->rect);

    current->cursor = spt;
    current->click_action = 3;
    current->scenes->game->hud->infos->money->value -= 500;
    sfMouse_setPosition((sfVector2i){btn_pos.x + 64, btn_pos.y + 64}, \
    (sfWindow*)current->window);
}

void event_tower_3_button(window_t* current)
{
    hud_t* hud = current->scenes->game->hud;

    if (current->event.type == sfEvtMouseButtonPressed && \
    button_is_clicked(hud->tower_3, \
    sfMouse_getPositionRenderWindow(current->window))) {
        hud->tower_3->callback(current);
    }
}

void draw_tower_3_button(window_t* current)
{
    if (current->scenes->game->hud->infos->money->value >= 500)
        event_tower_3_button(current);
    sfRenderWindow_drawRectangleShape(current->window, \
    current->scenes->game->hud->tower_3->rect, NULL);
}

button_t* init_tower_3_button(void)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &callback_tower_3_button;
    button_init(button, (sfVector2f){998, 925}, (sfVector2f){128, 128}, \
    "assets/img/turret3/turret_3.png");
    return (button);
}
