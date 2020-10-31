/*
** EPITECH PROJECT, 2018
** STRUCTS HEADER
** File description:
** HEADER
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SFML/Graphics.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} t_framebuffer;

typedef struct window {
    sfVideoMode mode;
    sfRenderWindow *window;
    t_framebuffer *buffer;
    sfSprite *sprite;
    sfTexture *texture;
    sfEvent event;
} window_t;

#endif /* !WINDOW_H_ */
