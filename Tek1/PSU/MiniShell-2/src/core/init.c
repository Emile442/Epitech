/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** init
*/


#include "my_shell.h"

shell_t* init_shell(char** env)
{
    shell_t* shell = malloc(sizeof(shell_t));

    shell->env = init_env(env);
    shell->exit = false;
    shell->code = 0;
    shell->command = NULL;
    if (shell->env == NULL || !shell->env[0])
        shell->env = default_env();
    return (shell);
}
