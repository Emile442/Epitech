/*
** EPITECH PROJECT, 2018
** graphics_utils
** File description:
** Graphics Utils
*/

#include <SFML/Graphics.h>
#include "my.h"

sfIntRect set_scale(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void show_help(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_hunter [-h]\n");
    my_printf("DESCRIPTION:\n");
    my_printf("     MyHunter is simple shoot game, you have 3 lifes\n");
}