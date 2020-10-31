/*
** EPITECH PROJECT, 2018
** parallax_init
** File description:
** Parallax init
*/

#include "my.h"
#include "my_runner.h"

static void new_parallax(sprite_texture_t *pr, char* filepath, sfVector2f pos)
{
    pr->texture = sfTexture_createFromFile(filepath, NULL);
    pr->sprite = sfSprite_create();
    pr->pos = pos;
    sfSprite_setTexture(pr->sprite, pr->texture, sfTrue);
    sfSprite_setPosition(pr->sprite, pr->pos);
}

static void p_item_init(sprite_texture_t *org, sprite_texture_t *cpy, \
char *path)
{
    new_parallax(org, path, (sfVector2f){0, 0});
    new_parallax(cpy, path, (sfVector2f){1920, 0});
}

void init_parallax(window_t *current)
{
    char* parallax_img[4] = {"assets/img/parallax/1_background.png", \
        "assets/img/parallax/2_midground.png", \
        "assets/img/parallax/3_foreground.png", \
        "assets/img/parallax/4_ground.png"};

    current->parallax = malloc(sizeof(parallax_t));
    current->parallax->background = malloc(sizeof(sprite_texture_t));
    current->parallax->midground = malloc(sizeof(sprite_texture_t));
    current->parallax->midground_copy = malloc(sizeof(sprite_texture_t));
    current->parallax->foreground = malloc(sizeof(sprite_texture_t));
    current->parallax->foreground_copy = malloc(sizeof(sprite_texture_t));
    current->parallax->ground = malloc(sizeof(sprite_texture_t));
    current->parallax->ground_copy = malloc(sizeof(sprite_texture_t));
    init_sprite(current->parallax->background, parallax_img[0]);
    p_item_init(current->parallax->midground, \
    current->parallax->midground_copy, parallax_img[1]);
    p_item_init(current->parallax->foreground, \
    current->parallax->foreground_copy, parallax_img[2]);
    p_item_init(current->parallax->ground, \
    current->parallax->ground_copy, parallax_img[3]);
}
