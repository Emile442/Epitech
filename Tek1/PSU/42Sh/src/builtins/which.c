/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** which
*/

#include "sh.h"

char** make_which(shell_t* shell)
{
    char** path = get_path(shell->env);
    char* cmd = NULL;

    for (int i = 1; shell->command[i]; i++) {
        cmd = find_base_cmd(shell->command[i], path);
        if (!cmd || my_strcmp(cmd, shell->command[i]))
            printf("%s: %s.\n", shell->command[i], ERR_CMD_NTF);
        else if (is_builtins(shell->command[i]))
            printf("%s: shell built-in command.\n", shell->command[i]);
        else
            printf("%s\n", cmd);
        free(cmd);
    }
    free(path);
    return (shell->env);
}
