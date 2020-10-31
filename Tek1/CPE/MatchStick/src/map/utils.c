/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** Utils
*/

#include "my.h"
#include "matchstick.h"

int count_line_stick(char* line)
{
    int count_stick = 0;
    bool stick = false;

    for (int i = 1; line[i]; i++) {
        if (!stick && line[i] == '|')
            stick = true;
        if (stick && line[i] == '|')
            count_stick++;
        if (stick && line[i] != '|')
            break;
    }
    return (count_stick);
}

bool map_can_supr(char* line, int value, int limit)
{
    if (value < 1 || value > limit || value > count_line_stick(line))
        return (false);
    return (true);
}

bool can_select_line(char** map, int value, int limit)
{
    if (value < 1 || value > 99 || value > limit || \
        count_line_stick(map[value]) == 0)
        return (false);
    return (true);
}
