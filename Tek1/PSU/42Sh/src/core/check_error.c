/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** Check_error.c
*/

#include <sh.h>

int print_error(char *cmd)
{
    int state = 1;

    if (errno == ENOEXEC) {
        state = 0;
        dprintf(2, "%s: %s.\n", cmd, ERR_FORMAT);
    }
    if (errno == ENOMEM) {
        state = 0;
        dprintf(2, "error\n");
    }
    if (state)
        dprintf(2, "%s\n", strerror(errno));
    return (0);
}

int print_child_error(int status)
{
    int state = 1;
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV && state) {
            state = 0;
            dprintf(2, "%s\n", ERR_SEGV);
        }
        if (WTERMSIG(status) == SIGFPE && state) {
            state = 0;
            dprintf(2, "%s\n", ERR_FPR);
        }
        if (state)
            dprintf(2, "%s\n", strerror(WTERMSIG(status)));
    }
    return (0);
}
