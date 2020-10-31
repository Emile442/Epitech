/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** unsetenv_cmd
*/


#include "my_shell.h"

int get_env2(char** env, char* target)
{
    int length = my_strlen(target);
    int i = 0;

    for (; env[i]; i++)
        if (my_strncmp(target, env[i], length) == 0 && env[i][length] == '=')
            break;
    return (i);
}

char** del_env(char** env, char* key)
{
    char** tmp;
    int i = 0;
    int k = 0;
    int p;

    for (; env[i]; i++);
    tmp = malloc(sizeof(char*) * (i+2));
    p = get_env2(env, key);
    for (int j = 0; env[j]; j++) {
        if (p != j) {
            tmp[k] = my_strdup(env[j]);
            k++;
        }
    }
    tmp[k] = NULL;
    free(env);
    return (tmp);
}

int unsetenv_cmd(shell_t* shell)
{
    if (!shell->command[1]) {
        my_printf("unsetenv: Too few arguments.\n");
        return (0);
    }
    shell->env = del_env(shell->env, shell->command[1]);
    return (0);
}
