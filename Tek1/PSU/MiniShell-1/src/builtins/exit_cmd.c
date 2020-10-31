/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exit_cmd
*/

#include "my.h"
#include "my_shell.h"

int exit_cmd(shell_t* shell)
{
    if (shell->command[1] != NULL) {
        if (my_str_isnum(shell->command[1])) {
            shell->exit = true;
            shell->code = my_getnbr(shell->command[1]);
        } else {
            my_printf("exit: %s\n", EXIT_ERR);
        }
    } else
        shell->exit = true;
    return (0);
}
