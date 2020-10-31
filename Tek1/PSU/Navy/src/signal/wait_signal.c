/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** wait_signal
*/

#include "../../include/navy.h"

void signal_handler(int signal, siginfo_t* info, void* null)
{
    int pid = stock_pid(0, false);

    (void)null;
    if (pid && pid != info->si_pid)
        return;
    if (signal == SIGUSR1)
        stock_bits(false, 0);
    else if (signal == SIGUSR2)
        stock_bits(false, 1);
    stock_pid(info->si_pid, true);
}

int define_signalhandler(void)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = signal_handler;
    if (sigaction(SIGUSR1, &sig, NULL) < 0)
        return (84);
    if (sigaction(SIGUSR2, &sig, NULL) <0)
        return (84);
    return (0);
}

int wait_signal(int code, void (*callback)(void))
{
    int nbr;

    while ((nbr = stock_bits(true, 0)) == -1);
    if (code == -1 || nbr != code)
        return (nbr);
    callback();
    return (stock_pid(0, false));
}
