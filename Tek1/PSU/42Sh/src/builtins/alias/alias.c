/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** builtins/alias
*/

#include "sh.h"

void print_alias(list_t **list)
{
    list_t *tmp = *list;

    for (; tmp; tmp = tmp->next)
        if (str_have(tmp->data->value, ' '))
            printf("%s\t(%s)\n", tmp->data->key, tmp->data->value);
        else
            printf("%s\t%s\n", tmp->data->key, tmp->data->value);
}

bool alias_has_error(shell_t* shell)
{
    char** command = shell->command;

    if (!command[1] || !command[2])
        return (true);
    if (!my_str_isalphanum(command[1]))
        return (true);
    return (false);
}

char* build_alias_cmd(char** command)
{
    char* tmp = NULL;
    int length = 0;

    for (int i = 2; command[i]; i++, length++)
        for (int j = 0; command[i][j]; j++, length++);
    tmp = malloc(sizeof(char *) * length + 1);
    strcpy(tmp, command[2]);
    for (int i = 3; command[i]; i++) {
        strcat(tmp, " ");
        strcat(tmp, command[i]);
    }
    return (tmp);
}

char **make_alias(shell_t* shell)
{
    data_t* data = malloc(sizeof(data_t));

    if (!shell->command[1])
        print_alias(&shell->alias);
    if (alias_has_error(shell))
        return (shell->env);
    data->key = shell->command[1];
    data->value = build_alias_cmd(shell->command);
    if (search_list(&shell->alias, shell->command[1]))
        pull_list(&shell->alias);
    push_list(&shell->alias, data);
    return (shell->env);
}
