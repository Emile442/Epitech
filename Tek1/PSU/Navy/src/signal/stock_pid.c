/*
** EPITECH PROJECT, 2019
** stock pid
** File description:
** stocks the pid
*/

#include <stdbool.h>

int stock_pid(int pid, bool stock)
{
    static int pid_stock = 0;

    if (stock)
        pid_stock = pid;
    return (pid_stock);
}
