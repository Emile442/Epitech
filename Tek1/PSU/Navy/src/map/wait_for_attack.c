/*
** EPITECH PROJECT, 2019
** wait for attack
** File description:
** wait for attak
*/

#include "navy.h"

int wait_for_attack(char **map, int pid)
{
    int attack;
    int x;
    int y;
    int status;

    my_printf("waiting for enemy's attack...\n");
    attack = wait_signal(-1, NULL);
    x = attack % 10;
    y = attack / 10;
    if ((status = verify_local_attack(map, x, y)))
        send_signal(1, pid);
    else
        send_signal(0, pid);
    my_printf("%c%c: %s\n", 'A' + y, '1' + x, status ? "hit" : "missed");
    return (0);
}
