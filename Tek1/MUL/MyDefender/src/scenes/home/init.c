/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** home/init
*/


#include "my_defender.h"

home_t* home_init(void)
{
    home_t* home = malloc(sizeof(home_t));

    home->background = init_spt("assets/img/home_background.jpg");
    home->play = init_play_button();
    home->quit = home_init_quit_button();
    return (home);
}
