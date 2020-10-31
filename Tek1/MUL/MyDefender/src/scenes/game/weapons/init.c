/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/init
*/

#include "my_defender.h"

sprite_texture_t** weapons_init(void)
{
    sprite_texture_t** weapons = malloc(sizeof(sprite_texture_t) * 100);

    weapons[0] = NULL;
    return (weapons);
}
