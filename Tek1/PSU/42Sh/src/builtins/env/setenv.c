/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** env/setenv
*/

#include <sh.h>


char **make_setenv(shell_t* shell)
{
    char** env = shell->env;
    char** av = shell->command;
    int len = my_strarray_len(env);
    char **new_env;
    char *new_var;

    if (!(new_var = check_setenv(shell)))
        return (env);
    for (int i = 0; env[i]; i++)
        if (my_strncmp(new_var, env[i], my_strlen(av[1]))) {
            env[i] = new_var;
            return (env);
        }
    if (!(new_env = malloc(sizeof(char *) * (len + 2))))
        exit(84);
    for (int i = 0; env[i]; new_env[i] = my_strcpy(env[i]), i++);
    new_env[len] = new_var;
    new_env[len + 1] = NULL;
    return (new_env);
}
