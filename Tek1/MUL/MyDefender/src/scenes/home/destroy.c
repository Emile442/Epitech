/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** home/destroy
*/

#include "my_defender.h"

void home_play_button_destroy(button_t* play);

void home_destroy(home_t* home)
{
    home_play_button_destroy(home->play);
    home_quit_button_destroy(home->quit);
    destroy_spt(home->background);
    free(home);
}
