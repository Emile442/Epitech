/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/button_tower_available
*/

#include "my_defender.h"

void callback_tower_available_button(window_t* current, button_t* button)
{
    if (current->click_action != 0) {
        weapon_add_by_coord(current, button->position);
        button->hidden = true;
    }
}

void draw_towers_available_button(window_t* current)
{
    hud_t* hud = current->scenes->game->hud;

    if (hud->available_slot == 0)
        return;
    for (int i = 0; i != hud->available_slot; i++) {
        if (hud->towers_available[i]->hidden == true)
            continue;
        if (current->event.type == sfEvtMouseButtonPressed && \
        button_is_clicked(hud->towers_available[i], \
        sfMouse_getPositionRenderWindow(current->window))) {
            hud->towers_available[i]->callback(current, \
            hud->towers_available[i]);
        }
        sfRenderWindow_drawRectangleShape(current->window, \
        hud->towers_available[i]->rect, NULL);
    }
}

button_t* init_available_tower(sfVector2f position)
{
    button_t* button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->callback = &callback_tower_available_button;
    button_init(button, position, (sfVector2f){128, 128}, \
    "assets/img/turret_available.png");
    return (button);
}

void add_tower_available_button(hud_t* hud, sfVector2f position)
{
    hud->towers_available[hud->available_slot] = init_available_tower(position);
    hud->towers_available[hud->available_slot + 1] = NULL;
    hud->available_slot++;
}

button_t** init_towers_available_button(void)
{
    button_t** buttons = malloc(sizeof(button_t) * 100);

    buttons[0] = NULL;
    return (buttons);
}
