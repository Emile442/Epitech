/*
** EPITECH PROJECT, 2019
** main loop
** File description:
** for Need4Stek
*/

#include "n4s.h"

bool is_finished(s_n4s *n4s)
{
    if (my_strcmp(n4s->get_info[35], "Track Cleared") == 0)
        return (true);
    return (false);
}

int main_loop(s_n4s *n4s)
{
    if (start_or_stop_simulation("START_SIMULATION\n") == false)
        return (84);
    while (1) {
        get_info_lidar(n4s);
        slow_down_speed_car(n4s);
        rotation_car(n4s);
        if (is_finished(n4s) == true)
            break;
    }
    dprintf(1, "CAR_FORWARD:0.0\n");
    n4s->buf = get_command_player();
    dprintf(1, "CYCLE_WAIT:20\n");
    n4s->buf = get_command_player();
    if (start_or_stop_simulation("STOP_SIMULATION\n") == false)
        return (84);
    return (0);
}
