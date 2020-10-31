/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Manage separators
*/

#include <sh.h>

int switch_stdout(int fd)
{
    (void)fd;
    return (0);
}

int manage_separator(shell_t *shell, int i, int state)
{
    if (!my_strcmp(CURRENT_CMD(shell), ";") && !NEXT_CMD(shell)) {
        dprintf(2, "Invalid null comand.\n");
        return (-1);
    }
    if (my_strcmp(CURRENT_CMD(shell), "&&") && !state)
        return (multiple_exec(shell, i + 1));
    if (my_strcmp(CURRENT_CMD(shell), "||") && state == -1)
        return (multiple_exec(shell, i + 1));
    if (my_strcmp(CURRENT_CMD(shell), ";"))
        return (multiple_exec(shell, i + 1));
    return (0);
}

int manage_pipe(shell_t *shell, int i, int *prev_fd)
{
    int fd[3] = {0};

    (void)prev_fd;
    if (my_strcmp(shell->all_commands[i + 1], "|")) {
        switch_stdout(fd[1]);
    }
    return (0);
}
