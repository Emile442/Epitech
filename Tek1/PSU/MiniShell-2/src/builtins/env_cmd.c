/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** env_cmd
*/


#include "my_shell.h"

int env_cmd(shell_t* shell)
{
    for (int i = 0; shell->env[i]; i++)
        my_printf("%s\n", shell->env[i]);
    return (0);
}
