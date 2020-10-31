/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exec
*/


#include "my_shell.h"

bool exec_c(shell_t* shell, char* bin)
{
    if ((execve(bin, shell->command, shell->env)) == -1)
        my_printf("%s: %s\n", shell->command[0], ERR_FORMAT);
    return (true);
}
