/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** hud/destroy
*/

#include "my_defender.h"

void hud_destroy(hud_t* hud)
{
    button_destroy(hud->pause);
    free(hud->pause);
    button_destroy(hud->tower_1);
    free(hud->tower_1);
    button_destroy(hud->tower_2);
    free(hud->tower_2);
    button_destroy(hud->tower_3);
    free(hud->tower_3);
    button_destroy(hud->plane);
    free(hud->plane);
    if (hud->available_slot != 0) {
        for (int i = 0; i != hud->available_slot; i++) {
            button_destroy(hud->towers_available[i]);
            free(hud->towers_available[i]);
        }
    }
    free(hud->towers_available);
    destroy_infos(hud->infos);
}
