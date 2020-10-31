/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/init
*/

#include "my_defender.h"

void tower_slot_init(hud_t* hud)
{
    add_tower_available_button(hud, (sfVector2f){390, 490});
    add_tower_available_button(hud, (sfVector2f){390, 200});
    add_tower_available_button(hud, (sfVector2f){760, 220});
    add_tower_available_button(hud, (sfVector2f){760, 465});
    add_tower_available_button(hud, (sfVector2f){760, 700});
    add_tower_available_button(hud, (sfVector2f){1160, 220});
    add_tower_available_button(hud, (sfVector2f){1160, 465});
    add_tower_available_button(hud, (sfVector2f){1160, 700});
    add_tower_available_button(hud, (sfVector2f){1530, 490});
    add_tower_available_button(hud, (sfVector2f){1530, 200});
}

hud_t* hud_init(void)
{
    hud_t* hud = malloc(sizeof(hud_t));

    hud->tower_1 = init_tower_1_button();
    hud->tower_2 = init_tower_2_button();
    hud->tower_3 = init_tower_3_button();
    hud->plane = init_plane_button();
    hud->available_slot = 0;
    hud->towers_available = init_towers_available_button();
    hud->pause = init_pause_button();
    hud->infos = init_info();
    tower_slot_init(hud);
    return (hud);
}
