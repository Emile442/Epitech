/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause/destroy
*/

#include "my_defender.h"

void pause_destroy(pause_t* pause)
{
    pause_quit_button_destroy(pause->quit);
    pause_resume_button_destroy(pause->resume);
    pause_home_button_destroy(pause->home);
    destroy_spt(pause->background);
    free(pause);
}
