/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** slow_down
*/

#include "n4s.h"

void select_speed(s_n4s *n4s)
{
    if (n4s->front >= 1900)
        n4s->speed = 1.0;
    if (n4s->front >= 1400 && n4s->front <= 1900)
        n4s->speed = 0.75;
    if (n4s->front >= 1000 && n4s->front <= 1400)
        n4s->speed = 0.55;
    if (n4s->front >= 600 && n4s->front <= 1000)
        n4s->speed = 0.40;
    if (n4s->front >= 400 && n4s->front <= 600)
        n4s->speed = 0.15;
    if (n4s->front >= 200 && n4s->front <= 400)
        n4s->speed = 0.10;
    if (n4s->front <= 200)
        n4s->speed = 0.01;
}

bool slow_down_speed_car(s_n4s *n4s)
{
    n4s->i = 0;
    n4s->front = atof(n4s->get_info[18]);
    select_speed(n4s);
    dprintf(1, "CAR_FORWARD:%f\n", n4s->speed);
    n4s->buf = get_command_player();
    for (; n4s->buf[n4s->i] != ':' && n4s->buf[n4s->i] != '\0'; n4s->i++);
    if (n4s->buf[n4s->i + 1] == 'K' && n4s->buf[n4s->i + 2] == 'O')
        return (false);
    return (true);
}
