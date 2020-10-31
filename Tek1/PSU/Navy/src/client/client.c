/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** client
*/

#include "../../include/navy.h"

void print_success_message(void)
{
    my_printf("successfully connected\n\n");
}

int run_client(char** map, int pid)
{
    char **enemy_map = initialize_map();

    if (!enemy_map)
        return (84);
    stock_pid(pid, true);
    send_signal(1, pid);
    if (wait_signal(1, print_success_message) != pid)
        return (84);
    while (true) {
        print_game(map, enemy_map);
        wait_for_attack(map, pid);
        my_printf("\n");
        if (gameover(map))
            return (my_printf("Enemy won\n")%1 + 1);
        if (!send_attack(enemy_map, pid))
            return (0);
        my_printf("\n");
        if (gameover(enemy_map))
            return (my_printf("I won\n")%1);
    }
}
