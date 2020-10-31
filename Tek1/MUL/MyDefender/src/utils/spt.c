/*
** EPITECH PROJECT, 2018
** spt
** File description:
** spt
*/

#include "my_defender.h"

sprite_texture_t* init_spt(char* path)
{
    sprite_texture_t* spt = malloc(sizeof(sprite_texture_t));

    spt->texture = sfTexture_createFromFile(path, NULL);
    spt->sprite = sfSprite_create();
    spt->angle = 0;
    spt->position = (sfVector2f){0, 0};
    sfSprite_setTexture(spt->sprite, spt->texture, sfTrue);
    return (spt);
}

void destroy_spt(sprite_texture_t* spt)
{
    sfSprite_destroy(spt->sprite);
    sfTexture_destroy(spt->texture);
    free(spt);
}
