/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "my_hunter.h"
#include "my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *array = malloc(sizeof(framebuffer_t));
    array->width = width;
    array->height = height;
    array->pixels = malloc(width * height * 4);
    return (array);
}

window_t *init_frame(int width, int height, int bits)
{
    char *s = "My Hunter";
    window_t *current = malloc(sizeof(window_t));
    sfVideoMode mode = {width, height, bits};

    current->bird = malloc(sizeof(bird_t));
    current->background = malloc(sizeof(sprite_texture_t));
    current->play_button = malloc(sizeof(sprite_texture_t));
    current->restart_button = malloc(sizeof(sprite_texture_t));
    current->exit_button = malloc(sizeof(sprite_texture_t));
    current->scope = malloc(sizeof(sprite_texture_t));
    current->scoreboard = malloc(sizeof(scoreboard_t));
    current->mode = mode;
    init_scoreboard(current);
    init_lifes(current);
    init_button(current);
    current->window = sfRenderWindow_create(current->mode, s, sfClose, NULL);
    current->buffer = framebuffer_create(width, height);
    set_scope_bg_button(current);
    bird_init(current);
    reset_bird(current);
    return (current);
}

void destroy_game(window_t *current)
{
    sfSprite_destroy(current->background->sprite);
    sfSprite_destroy(current->bird->sprite);
    sfTexture_destroy(current->background->texture);
    sfSprite_destroy(current->play_button->sprite);
    sfSprite_destroy(current->scope->sprite);
    sfTexture_destroy(current->play_button->texture);
    sfTexture_destroy(current->bird->texture);
    sfTexture_destroy(current->scope->texture);
    sfMusic_destroy(current->bird->fire);
    sfRenderWindow_destroy(current->window);
    free(current->background);
    free(current->play_button);
    free(current->scope);
    free(current->buffer);
    free(current->bird);
    free(current);
}

void draw_frame(window_t *current)
{
    sfVector2i mouse_pos;
    sfVector2f scope_pos;

    sfRenderWindow_setMouseCursorVisible(current->window, sfFalse);
    sfRenderWindow_clear(current->window, sfBlack);
    mouse_pos = sfMouse_getPositionRenderWindow(current->window);
    scope_pos.x = mouse_pos.x - 100;
    scope_pos.y = mouse_pos.y - 100;
    sfRenderWindow_drawSprite(current->window, \
    current->background->sprite, NULL);
    button_display(current);
    sfRenderWindow_drawSprite(current->window, current->scope->sprite, NULL);
    sfSprite_setPosition(current->scope->sprite, scope_pos);
    sfRenderWindow_drawText(current->window, current->scoreboard->text, NULL);
    life_display(current);
}

int main(int ac, char **av)
{
    window_t *current;
    sfClock *anim_clock = sfClock_create();

    if (ac == 2 &&!my_strcmp(av[1], "-h")) {
        show_help();
        return (0);
    }
    current = init_frame(1920, 1080, 32);
    if (!current->window)
        return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(current->window, 60);
    while (sfRenderWindow_isOpen(current->window)) {
        event_listener(current);
        draw_frame(current);
        sfRenderWindow_display(current->window);
        if (sfClock_getElapsedTime(anim_clock).microseconds / 1000 > 100)
            bird_anim(anim_clock, current);
    }
    destroy_game(current);
    return (0);
}