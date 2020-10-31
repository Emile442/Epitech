/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias/find_cmd
*/

#include "sh.h"

char** recompile_cmd(char** command)
{
    char** tmp = NULL;
    char** tmp_new_cmd = my_str_to_word_array(command[0]);
    int i = 0;
    int k = 0;

    for (; tmp_new_cmd[i]; i++);
    if (i == 1){
        free_dchar(tmp_new_cmd);
        return (command);
    }
    for (int j = 0; command[j]; j++, i++);
    tmp = malloc(sizeof(char*) * i + 1);
    for (int c = 0; tmp_new_cmd[c]; c++, k++)
        tmp[k] = tmp_new_cmd[c];
    for (int c = 1; command[c]; c++, k++)
        tmp[k] = command[c];
    tmp[k] = NULL;
    return (tmp);
}

void replace_alias(shell_t* shell)
{
    while (search_list(&shell->alias, shell->command[0]))
        shell->command[0] = strdup(shell->alias->data->value);
    shell->command = recompile_cmd(shell->command);
}
