/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** dispatch
*/


#include "my_shell.h"

int dispatch_cmd(shell_t* shell)
{
    if (!my_strcmp(shell->command[0], "exit"))
        return (exit_cmd(shell));
    if (!my_strcmp(shell->command[0], "env"))
        return (env_cmd(shell));
    if (!my_strcmp(shell->command[0], "setenv"))
        return (setenv_cmd(shell));
    if (!my_strcmp(shell->command[0], "unsetenv"))
        return (unsetenv_cmd(shell));
    if (!my_strcmp(shell->command[0], "cd"))
        return (cd_cmd(shell));
    exec_command(shell);
    return (0);
}
