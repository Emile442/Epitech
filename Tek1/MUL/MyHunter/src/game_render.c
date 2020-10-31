/*
** EPITECH PROJECT, 2018
** game_render
** File description:
** Game render
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#include "my_hunter.h"
#include "my.h"

void set_scope_bg_button(window_t *current)
{
    sfVector2f button_coord = {(1920 / 2) - (482 / 2), (1080 / 2) - (169 / 2)};
    char* path[] = {"img/background.jpg", "img/scope.png", \
        "img/play-button.png"};

    current->background->texture = sfTexture_createFromFile(path[0], NULL);
    current->background->sprite = sfSprite_create();
    sfSprite_setTexture(current->background->sprite, \
    current->background->texture, sfTrue);
    current->scope->texture = sfTexture_createFromFile(path[1], NULL);
    current->scope->sprite = sfSprite_create();
    sfSprite_setTexture(current->scope->sprite, \
    current->scope->texture, sfTrue);
    current->play_button->texture = sfTexture_createFromFile(path[2], NULL);
    current->play_button->sprite = sfSprite_create();
    sfSprite_setTexture(current->play_button->sprite, \
    current->play_button->texture, sfTrue);
    sfSprite_move(current->play_button->sprite, button_coord);
}

void life_display(window_t *current)
{
    if (current->lives == 1)
        sfRenderWindow_drawSprite(current->window, \
        current->life->one->sprite, NULL);
    if (current->lives == 2)
        sfRenderWindow_drawSprite(current->window, \
        current->life->two->sprite, NULL);
    if (current->lives == 3)
        sfRenderWindow_drawSprite(current->window, \
        current->life->three->sprite, NULL);
}

void init_lifes(window_t *current)
{
    char* path[] = {"img/heart-1.png", "img/heart-2.png", \
        "img/heart-3.png"};

    current->life = malloc(sizeof(lifes_t));
    current->life->one = malloc(sizeof(sprite_texture_t));
    current->life->two = malloc(sizeof(sprite_texture_t));
    current->life->three = malloc(sizeof(sprite_texture_t));
    current->life->one->texture = sfTexture_createFromFile(path[0], NULL);
    current->life->one->sprite = sfSprite_create();
    sfSprite_setTexture(current->life->one->sprite, \
    current->life->one->texture , sfTrue);
    current->life->two->texture = sfTexture_createFromFile(path[1], NULL);
    current->life->two->sprite = sfSprite_create();
    sfSprite_setTexture(current->life->two->sprite, \
    current->life->two->texture , sfTrue);
    current->life->three->texture = sfTexture_createFromFile(path[2], NULL);
    current->life->three->sprite = sfSprite_create();
    sfSprite_setTexture(current->life->three->sprite, \
    current->life->three->texture , sfTrue);
}

void button_display(window_t *current)
{
    if (current->status == 0)
        sfRenderWindow_drawSprite(current->window, \
        current->play_button->sprite, NULL);
    if (current->status == 1)
        sfRenderWindow_drawSprite(current->window, current->bird->sprite, NULL);
    if (current->status == 2) {
        sfRenderWindow_drawSprite(current->window, \
        current->exit_button->sprite, NULL);
        sfRenderWindow_drawSprite(current->window, \
        current->restart_button->sprite, NULL);
    }
}

void init_button(window_t *current)
{
    sfVector2f exit_coord = {(1920 / 2) - (482 / 2), 550};
    sfVector2f restart_coord = {(1920 / 2) - (482 / 2), 350};
    char* path[] = {"img/exit-button.png", "img/restart-button.png"};

    current->exit_button->texture = sfTexture_createFromFile(path[0], NULL);
    current->exit_button->sprite = sfSprite_create();
    sfSprite_setTexture(current->exit_button->sprite, \
    current->exit_button->texture, sfTrue);
    current->restart_button->texture = sfTexture_createFromFile(path[1], NULL);
    current->restart_button->sprite = sfSprite_create();
    sfSprite_setTexture(current->restart_button->sprite, \
    current->restart_button->texture, sfTrue);
    sfSprite_move(current->exit_button->sprite, exit_coord);
    sfSprite_move(current->restart_button->sprite, restart_coord);
}