/*
** EPITECH PROJECT, 2018
** score_init
** File description:
** Score init
*/

#include "my.h"
#include "my_runner.h"

void score_init(window_t *current)
{
    current->scoreboard = malloc(sizeof(scoreboard_t));
    current->scoreboard->score_img = malloc(sizeof(sprite_texture_t));
    current->scoreboard->score_img->texture = sfTexture_createFromFile(\
    "assets/img/score.png", NULL);
    current->scoreboard->score_img->sprite = sfSprite_create();
    sfSprite_setTexture(current->scoreboard->score_img->sprite, \
    current->scoreboard->score_img->texture, sfTrue);
    current->scoreboard->value = 0;
    current->scoreboard->font = sfFont_createFromFile(\
    "assets/font/scoreboard.ttf");
    current->scoreboard->text = sfText_create();
    sfText_setString(current->scoreboard->text, \
    int_to_str(current->scoreboard->value));
    sfText_setFont(current->scoreboard->text, current->scoreboard->font);
    sfText_setCharacterSize(current->scoreboard->text, 60);
    sfText_move(current->scoreboard->text, (sfVector2f){260, 46});
}
