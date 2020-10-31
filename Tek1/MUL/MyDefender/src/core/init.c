/*
** EPITECH PROJECT, 2018
** main
** File description:
** Main
*/

#include "my_defender.h"

scene_t* scene_init(void);
sprite_texture_t* cursor_init(void);

void default_click(void)
{
    return;
}

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
    char* s = "MyDefender";
    window_t *current = malloc(sizeof(window_t));
    sfVideoMode mode = {width, height, bits};

    current->mode = mode;
    current->window = sfRenderWindow_create(current->mode, s, sfClose, NULL);
    current->buffer = framebuffer_create(width, height);
    current->default_cursor = cursor_init();
    current->cursor = current->default_cursor;
    current->cursor_size = 128;
    current->scenes = scene_init();
    current->click = &default_click;
    current->exit = false;
    current->music_click = init_music("assets/music/click.ogg");
    cursor_to_default(current);
    sfRenderWindow_setMouseCursorVisible(current->window, sfFalse);
    sfRenderWindow_setFramerateLimit(current->window, 30);
    return (current);
}
