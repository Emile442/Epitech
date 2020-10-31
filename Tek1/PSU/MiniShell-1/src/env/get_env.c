/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** get_env
*/

#include "my.h"
#include "my_shell.h"

char* get_env(char** env, char* target)
{
    int length = my_strlen(target);
    char* tmp = "";

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(target, env[i], length) == 0 && env[i][length] == '=') {
            tmp = my_strdup(env[i] + length + 1);
            break;
        }
    }
    return (tmp);
}
