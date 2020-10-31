/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** core/prompt
*/

#include "sh.h"

char* get_entry(void)
{
    char* buffer;

    printf("\033[1;35m~>\033[0m ");
    fflush(0);
    buffer = get_next_line(0);
    if (!buffer)
        buffer = (my_strcpy("exit"));
    return (buffer);
}

int pre_exec(shell_t* shell, char* prompt)
{
    char **path = get_path(shell->env);

    shell->command = line_formating(prompt);
    if (!shell->command)
        return (-1);
    replace_alias(shell);
    if (make_basic_cmd(shell) && !my_strcmp(prompt, ""))
        if (execute_cmd(shell, path) == -1)
            return (-1);
    free_dchar(path);
    return (0);
}

int multiple_exec(shell_t *shell, int i)
{
    int state = 0;

    if (!shell->all_commands[i])
        return (0);
    state = pre_exec(shell, CURRENT_CMD(shell));
    if (NEXT_CMD(shell))
        manage_separator(shell, i + 1, state);
    return (state);
}

int mysh_loop(shell_t* shell)
{
    char* prompt = get_entry();

    if (!(shell->all_commands = parse_prompt(prompt)))
        return (0);
    return (multiple_exec(shell, 0));
}
