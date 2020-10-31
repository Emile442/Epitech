/*
** EPITECH PROJECT, 2018
** DRAW
** File description:
** Draw functions
*/

#include <SFML/Graphics.h>
#include <draw.h>

int put_pixel(t_framebuffer *framebuffer, unsigned int x, unsigned int y,
sfColor color)
{
    if (x >= 800 && y <= 800 && x <= 0 && y <= 0)
        return (84);

    int pixel_pos = (framebuffer->width * y + x) * 4;

    framebuffer->pixels[pixel_pos] = color.r;
    framebuffer->pixels[pixel_pos + 1] = color.g;
    framebuffer->pixels[pixel_pos + 2] = color.b;
    framebuffer->pixels[pixel_pos + 3] = color.a;
    return (0);
}

void draw_square(t_framebuffer *framebuffer, sfVector2u position,
unsigned int size, sfColor color)
{
    int x = position.x;
    int y = position.y;

    while (x < position.x + size) {
        y = position.y;
        while (y < position.y + size) {
            put_pixel(framebuffer, x, y, color);
            y++;
        }
        x++;
    }
}

void draw_components(window_t *window)
{
    put_pixel(window->buffer, 10, 10, sfRed);
    put_pixel(window->buffer, 100, 100, sfRed);
    put_pixel(window->buffer, 250, 400, sfRed);
    sfVector2u position = {100, 100};
    draw_square(window->buffer, position, 10, sfBlue);
    sfTexture_updateFromPixels(window->texture, window->buffer->pixels,
    window->buffer->width, window->buffer->height, 0, 0);
}