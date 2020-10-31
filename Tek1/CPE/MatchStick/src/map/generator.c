/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** map/create
*/

#include "my.h"
#include "matchstick.h"

static void fill_line(char* str, int column, int line, int maxLength)
{
    int nb_space = (column - line);
    int nb_stick = (maxLength - 2) - (nb_space * 2);
    int i = 0;

    str[i++] = '*';
    for (int j = 1; j <= nb_space; i++, j++)
        str[i] = ' ';
    for (int j = 1; j <= nb_stick; i++, j++)
        str[i] = '|';
    for (int j = 1; j <= nb_space; i++, j++)
        str[i] = ' ';
    str[i] = '*';
}

static void fill_full_line(char* str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '*';
}

char** map_generator(int nb)
{
    int cursor = 1;
    int maxLength = (nb * 2 + 1);
    char** map = malloc(sizeof(char*) * (nb + 3));

    for (int i = 0; i < (nb + 2); i++)
        map[i] = malloc(sizeof(char) * maxLength);
    fill_full_line(map[0], maxLength);
    for (int i = 1; i <= nb; i++, cursor++)
        fill_line(map[i], nb, i, maxLength);
    fill_full_line(map[cursor], maxLength);
    return (map);
}
