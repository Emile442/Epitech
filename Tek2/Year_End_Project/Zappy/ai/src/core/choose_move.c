/*
** EPITECH PROJECT, 2020
** cmds.c
** File description:
** cmds
*/

#include "zappy_ai.h"

void choose_dir(zappy_t *zappy, int status, int i, int size)
{
    int med = size / 2;
    if (status == 1 && i < med)
        go_left(zappy);
    if (status == 1 && i > med)
        go_right(zappy);
    if (status == 1 && i == med)
        go_forward(zappy);
    return;
}

int size_look(char **look)
{
    int i = 0;
    for (; look[i]; i++);
    return (i);
}

int next_step(zappy_t *zappy, char *str)
{
    int i = 0;
    int status = 0;
    char **look = parser_look(str);
    int size = size_look(look);
    for (; look[i]; i++) {
        printf("Look[%d] = %s.\n", i, look[i]);
        if (!strcmp(look[i], "FOOD")) {
            status = 1;
            choose_dir(zappy, status, i, size);
        }
        if (!strcmp(look[i], "NONE"))
            status = 2;
        else
            status = 3;
    }
    return (0);
}
