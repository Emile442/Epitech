/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** env/env
*/

#include "sh.h"

char **make_env(shell_t* shell)
{
    char** env = shell->env;
    char** av = shell->command;

    if (my_strarray_len(av) != 1) {
        dprintf(2, "env: %s: %s\n", av[1], ERR_DIR_FILE);
        return (env);
    }
    for (int i = 0; env[i]; i++)
        printf("%s\n", env[i]);
    return (env);
}
