/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** turn/ia_utils
*/

#include "my.h"
#include "matchstick.h"

int found_the_most_big_line(char** map)
{
    int big = 0;
    int line = 0;
    int tmp = 0;

    for (int i = 0; map[i]; i++) {
        tmp = count_line_stick(map[i]);
        if (tmp > big) {
            big = tmp;
            line = i;
        }
    }
    return (line);
}

int count_line_have_stick(char** map)
{
    int nbr = 0;

    for (int i = 0; map[i]; i++) {
        if (count_line_stick(map[i]))
            nbr++;
    }
    return (nbr);
}

bool is_pair(int nbr)
{
    if (nbr % 2 == 0)
        return (true);
    return (false);
}
