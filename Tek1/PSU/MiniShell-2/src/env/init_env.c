/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** init_env
*/


#include "my_shell.h"

char **default_env(void)
{
    char **env = NULL;
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    env = malloc(sizeof(char*) * (1));
    env = new_env(env, "PWD", pwd);
    env = new_env(env, "OLDPWD", pwd);
    env = new_env(env, "PATH", "/usr/bin:/bin");
    env = new_env(env, "HOME", "/");
    return (env);
}

char** init_env(char** env)
{
    char** tmp = NULL;
    int i = 0;

    if (env == NULL)
        return (tmp);
    for (; env[i]; i++);
    tmp = malloc(sizeof(char*) * (i + 1));
    for (int j = 0; env[j]; j++)
        tmp[j] = my_strdup(env[j]);
    return (tmp);
}
