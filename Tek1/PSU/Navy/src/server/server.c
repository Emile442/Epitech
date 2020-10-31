/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** server
*/

#include "navy.h"

void connection_success(void)
{
    my_printf("enemy connected\n\n");
}

int run_server(char** map)
{
    int pid;
    char** enemy_map = initialize_map();

    my_printf("waiting for enemy connection...\n\n");
    pid = wait_signal(1, connection_success);
    send_signal(1, pid);
    stock_pid(pid, true);
    while (true) {
        print_game(map, enemy_map);
        if (!send_attack(enemy_map, pid))
            return (0);
        my_printf("\n");
        if (gameover(enemy_map))
            return (my_printf("I won\n")%1);
        wait_for_attack(map, pid);
        my_printf("\n");
        if (gameover(map))
            return (my_printf("Enemy won\n")%1 + 1);
    }
}
