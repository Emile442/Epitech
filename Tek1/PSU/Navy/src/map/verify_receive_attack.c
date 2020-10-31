/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** verify_receive_attack
*/

#include "navy.h"

int verify_receive_attack(int coord, int pid)
{
    int status;

    send_signal(coord, pid);
    status = wait_signal(-1, NULL);
    if (status)
        return (true);
    return (false);
}

int send_attack(char** enemy_map, int pid)
{
    int coord = get_usr_input();
    int x = coord % 10;
    int y = coord / 10;
    int status;

    if (coord == -1)
        return (0);
    status = verify_receive_attack(coord, pid);
    if (status)
        hit(enemy_map, x, y);
    else
        missed(enemy_map, x, y);
    my_printf("%c%c: %s\n", 'A' + y, '1' + x, status ? "hit" : "missed");
    return (1);
}
