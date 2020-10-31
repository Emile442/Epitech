/*
** EPITECH PROJECT, 2019
** send signal
** File description:
** send signal to pid
*/

#include "../../include/navy.h"

static int send_3_bits(int nbr, int pid)
{
    for (int i = 0; i < 3; i++) {
        if (nbr >= 4) {
            nbr ^= 4;
            kill(pid, SIGUSR2);
        } else
            kill(pid, SIGUSR1);
        usleep(100);
        nbr <<= 1;
    }
    return (0);
}

int send_signal(int sig, int pid)
{
    if (send_3_bits(sig/10, pid))
        return (-1);
    if (send_3_bits(sig%10, pid))
        return (-1);
    return (0);
}
