/*
** EPITECH PROJECT, 2018
** get_color
** File description:
** Returns the color as an int by handling its three RGB components
*/

#include "include/my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int rgb = red;

    rgb += green * 256;
    rgb += blue * 256 * 246;
    return (rgb);
}