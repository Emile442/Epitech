/*
** EPITECH PROJECT, 2019
** rotation car
** File description:
** for Need4Stek
*/

#include "n4s.h"

void direction(float middle, s_n4s *n4s)
{
    if (middle >= 1000 && middle < 1800)
        n4s->dir = 0.05;
    if (middle >= 700 && middle < 1000)
        n4s->dir = 0.1;
    if (middle >= 400 && middle < 700)
        n4s->dir = 0.25;
    if (middle >= 150 && middle < 400)
        n4s->dir = 0.3;
    if (middle >= 50 && middle < 150)
        n4s->dir = 0.35;
    if (middle < 50)
        n4s->dir = 0.45;
}

void rotation_car(s_n4s *n4s)
{
    float left_or_right = atof(n4s->get_info[4]) - atof(n4s->get_info[34]);

    dprintf(1, "WHEELS_DIR:");
    if (left_or_right > 0.0) {
        direction(n4s->front, n4s);
        dprintf(1, "%f\n", n4s->dir);
    } else {
        direction(n4s->front, n4s);
        dprintf(1, "-%f\n", n4s->dir);
    }
    n4s->buf = get_command_player();
    n4s->i = 0;
    for (; n4s->buf[n4s->i] != ':' && n4s->buf[n4s->i] != '\0'; n4s->i++);
    if (n4s->buf[n4s->i + 1] == 'K' && n4s->buf[n4s->i + 2] == 'O')
        exit(84);
}
