/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** setenv_cmd
*/


#include "my_shell.h"

char* env_str(char* key, char* value)
{
    int len = my_strlen(key) + my_strlen(value) + 1;
    char* str = malloc(sizeof(char) * len);

    my_memset(str, '\0', len);
    my_strcpy(str, key);
    my_strcat(str, "=");
    if (my_strcmp(value, "") != 0)
        my_strcat(str, value);
    return (str);
}

char** new_env(char** env, char* key, char* value)
{
    char** tmp;
    int i = 0;

    for (; env[i]; i++);
    tmp = malloc(sizeof(char*) * (i+2));
    for (int j = 0; env[j]; j++)
        tmp[j] = my_strdup(env[j]);
    tmp[i] = my_strdup(env_str(key, value));
    return (tmp);
}

char** edit_env(char** env, char* key, char* value)
{
    int length = my_strlen(key);

    for (int i = 0; env[i]; i++)
        if (my_strncmp(key, env[i], length) == 0 && env[i][length] == '=')
            env[i] = my_strdup(env_str(key, value));
    return (env);
}

bool check_key(char c)
{
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') \
        || (c <= 9 && c >= 0) || c == '_')
        return (true);
    my_printf("setenv: %s\n", ENV_STR);
    return (false);
}

int setenv_cmd(shell_t* shell)
{
    char* key = shell->command[1];
    char* value = shell->command[2];

    if (!shell->command[2])
        value = "";
    if (my_strcmp(key, "") == 0) {
        env_cmd(shell);
        return (0);
    }
    for (int i = 0; key[i]; i++)
        if (!check_key(key[i]))
            return (0);
    if (my_strcmp(get_env(shell->env, key), "") == 0)
        shell->env = new_env(shell->env, key, value);
    else
        shell->env = edit_env(shell->env, key, value);
    return (0);
}
