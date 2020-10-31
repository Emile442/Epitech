/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** cd/utils
*/

#include "sh.h"


char **chdir_env(char *oldpath, shell_t* shell)
{
    char *tmp[] = {"setenv", "OLDPWD", oldpath, NULL};
    char buffer[1024];

    shell->command = tmp;
    shell->env = make_setenv(shell);
    tmp[1] = "PWD";
    tmp[2] = getcwd(buffer, 1024);
    shell->env = make_setenv(shell);
    return (shell->env);
}

char **make_chdir(shell_t* shell)
{
    char buffer[1024];
    char *path = NULL;
    char *to_go = NULL;
    char** av = shell->command;
    char** env = shell->env;

    to_go = av[1];
    if (my_strarray_len(av) != 1 && my_strarray_len(av) != 2)
        return (env);
    if (my_strarray_len(av) == 1)
        to_go = give_env_path("HOME=", env, to_go);
    else if (my_strcmp(av[1], "-"))
        to_go = give_env_path("OLDPWD=", env, to_go);
    path = getcwd(buffer, 1024);
    if (chdir(to_go) == -1)
        dprintf(2, "%s: %s.\n", to_go, strerror(errno));
    else
        env = chdir_env(path, shell);
    return (env);
}
