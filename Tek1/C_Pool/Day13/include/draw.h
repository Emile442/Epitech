/*
** EPITECH PROJECT, 2018
** DRAW HEADER
** File description:
** HEADER
*/

#include <structs.h>

int draw_window(int width, int height, int bits);
t_framebuffer * framebuffer_create(unsigned int width, unsigned int height);
window_t *init_frame(int width, int height, int bits);
int update_frame(window_t *current);
int put_pixel(t_framebuffer *framebuffer, unsigned int x, unsigned int y,
sfColor color);
void draw_components(window_t *window);