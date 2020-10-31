/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** builtins/repeat
*/

#include "sh.h"

bool repeat_has_error(char** command)
{
    if (!command[1]) {
        dprintf(2, "repeat: %s.\n", ERR_FEW_ARGS);
        return (true);
    }
    if (my_str_isnum(command[1])) {
        dprintf(2, "repeat: Badly formed number.\n");
        return (true);
    }
    return (false);
}

char* get_repeat_cmd(char** command)
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

char** make_repeat(shell_t* shell)
{
    char* repeat_cmd = NULL;

    if (repeat_has_error(shell->command))
        return (shell->env);
    repeat_cmd = get_repeat_cmd(shell->command);
    for (int i = 0, repeat = atoi(shell->command[1]); i != repeat; i++)
        pre_exec(shell, repeat_cmd);
    free(repeat_cmd);
    return (shell->env);
}
