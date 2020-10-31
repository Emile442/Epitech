/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/draw
*/

#include "my_defender.h"

void hud_draw(window_t* current)
{
    draw_tower_1_button(current);
    draw_tower_2_button(current);
    draw_tower_3_button(current);
    draw_plane_button(current);
    if (current->click_action != 0 && current->click_action != 4)
        draw_towers_available_button(current);
    draw_infos(current);
    pause_button_draw(current);
}
