/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** cursor/init
*/

#include "my_defender.h"

sprite_texture_t* cursor_init(void)
{
    sprite_texture_t* spt = init_spt("assets/img/cursor.png");

    return (spt);
}
