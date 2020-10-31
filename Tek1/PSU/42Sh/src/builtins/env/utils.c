/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** env/utils
*/

#include "sh.h"

char **remove_from_env(int nb, char **env)
{
    char **newenv = malloc(sizeof(char *) * my_strarray_len(env));

    for (int i = 0, j = 0; env[i]; i++, j++)
        if (i != nb)
            newenv[j] = my_strcpy(env[i]);
        else
            j--;
    newenv[my_strarray_len(env) - 1] = NULL;
    for (int i = 0; env[i]; free(env[i]), i++);
    free(env);
    return (newenv);
}

char *check_setenv(shell_t* shell)
{
    char *result = NULL;
    char **av = shell->command;

    if (my_strarray_len(av) == 1)
        make_env(shell);
    if (my_strarray_len(av) == 2) {
        if (!my_str_isalphanum(av[1]))
            dprintf(2, "setenv: %s.\n", ERR_ENV_STR);
        else
            result = my_strcat(av[1], "=");
    }
    if (my_strarray_len(av) == 3) {
        if (!my_str_isalphanum(av[1]))
            dprintf(2, "setenv: %s.\n", ERR_ENV_STR);
        result = my_strcat(av[1], "=");
        result = my_strcat(result, av[2]);
    }
    if (my_strarray_len(av) > 3)
        dprintf(2, "setenv: %s.\n", ERR_MUCH_ARGS);
    return (result);
}

char *give_env_path(char *to_find, char **env, char *arg)
{
    int len = my_strlen(to_find);

    for (int i = 0, state = 1; env[i] && state; i++)
        if (my_strncmp(to_find, env[i], len)) {
            arg = env[i] + len;
            state = 0;
        }
    return (arg);
}
