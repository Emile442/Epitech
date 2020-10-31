/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause/init
*/


#include "my_defender.h"

pause_t* pause_init(void)
{
    pause_t* pause = malloc(sizeof(pause_t));

    pause->background = init_spt("assets/img/pause_background.jpg");
    pause->quit = pause_init_quit_button();
    pause->resume = pause_init_resume_button();
    pause->home = pause_init_home_button();
    return (pause);
}
