/*
** EPITECH PROJECT, 2018
** game_init
** File description:
** Game init
*/

#include "my_runner.h"
#include "my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *array = malloc(sizeof(framebuffer_t));
    array->width = width;
    array->height = height;
    array->pixels = malloc(width * height * 4);
    return (array);
}

static void map_setup(window_t* current, char* path)
{
    if (!map_init(current, path)) {
        my_putstr("Erreur MAP\n");
        current->error = true;
    }
}

window_t *init_frame(int width, int height, int bits, char* path)
{
    char* s = "MyRunner";
    window_t *current = malloc(sizeof(window_t));
    sfVideoMode mode = {width, height, bits};

    current->mode = mode;
    current->window = sfRenderWindow_create(current->mode, s, sfClose, NULL);
    current->buffer = framebuffer_create(width, height);
    current->lives = 5;
    current->error = false;
    current->music = sfMusic_createFromFile(\
    "assets/music/music.ogg");
    sfMusic_play(current->music);
    sfRenderWindow_setFramerateLimit(current->window, 30);
    init_clock(current);
    init_parallax(current);
    set_player(current);
    score_init(current);
    map_setup(current, path);
    box_waiting(current);
    return (current);
}
