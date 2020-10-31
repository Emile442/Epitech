/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** env/devfault
*/

#include "sh.h"

void default_env(shell_t* shell)
{
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    shell->env = malloc(sizeof(char*) * (1));
    pre_exec(shell, strcat("PWD=", pwd));
    pre_exec(shell, strcat("OLDPWD=", pwd));
    pre_exec(shell, "PATH=/usr/bin:/bin");
    pre_exec(shell, "HOME=/");
}

char** init_env(void)
{
    char** my_env = NULL;
    char pwd[1024];

    my_env = malloc(sizeof(char *) * 5);
    if (!my_env)
        return (NULL);
    getcwd(pwd, sizeof(pwd));
    my_env[0] = my_strcpy(my_strcat("PWD=", pwd));
    my_env[1] = my_strcpy(my_strcat("OLDPWD=", pwd));
    my_env[2] = my_strcpy("PATH=/usr/bin:/bin");
    my_env[3] = my_strcpy("HOME=/");
    my_env[4] = NULL;
    return (my_env);
}
