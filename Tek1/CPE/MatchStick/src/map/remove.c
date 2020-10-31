/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** map/remove
*/

#include "my.h"
#include "matchstick.h"

int map_remove(char** map, int line, int nb_matches)
{
    bool stick = false;
    int last_stick = 0;
    int count_stick = 0;

    for (int i = 1; map[line][i]; i++, last_stick++) {
        if (!stick && map[line][i] == '|')
            stick = true;
        if (stick && map[line][i] == '|')
            count_stick++;
        if (stick && map[line][i] != '|')
            break;
    }
    if (nb_matches > count_stick)
        return (-1);
    for (; nb_matches != 0; nb_matches--, last_stick--)
        map[line][last_stick] = ' ';
    return (0);
}
