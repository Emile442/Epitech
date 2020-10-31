/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** env/unsetenv
*/

#include "sh.h"

char **make_unsetenv(shell_t* shell)
{
    char** env = shell->env;
    char** av = shell->command;

    if (my_strarray_len(av) < 1) {
        dprintf(2, "unsetenv: %s\n", ERR_FEW_ARGS);
        return (env);
    }
    for (int i = 1; av[i]; av[i] = my_strcat(av[i], "="), i++);
    for (int i = 0, j = 1; env[i] && av[j]; i++) {
        if (my_strncmp(av[j], env[i], my_strlen(av[j]))) {
            env = remove_from_env(i, env);
            i = 0;
            j++;
        }
        (!env[i + 1]) ? i = 0, j++ : 0;
    }
    return (env);
}
