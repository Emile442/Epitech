/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** get_env_path
*/


#include "my_shell.h"

char** get_env_path(char** env)
{
    char* env_path = get_env(env, "PATH");
    char** paths;

    for (int i = 0; env_path[i]; i++)
        if (env_path[i] == ':')
            env_path[i] = ' ';
    paths = my_str_to_word_array(env_path);
    return (paths);
}
