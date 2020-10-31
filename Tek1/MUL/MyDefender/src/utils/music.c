/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** click_song
*/

#include "my_defender.h"

sfMusic* init_music(char* path)
{
    sfMusic* music = sfMusic_createFromFile(path);

    return (music);
}

void destroy_music(sfMusic* music)
{
    sfMusic_destroy(music);
}
