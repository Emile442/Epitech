/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** prompt
*/

#include "my_shell.h"

char* get_command(void)
{
    char* buffer = NULL;
    size_t len = 0;
    int c;

    c = getline(&buffer, &len, stdin);
    if (c == -1)
        return ("exit\n");
    return (buffer);
}

char* clean_str(char* str)
{
    char* tmp = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0, j = 0; str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] &&
            (str[i + 1] == ' ' || str[i + 1] == '\t'))
            continue;
        tmp[j] = str[i];
        j++;
    }
    return (tmp);
}

void prompt_loop(shell_t* shell)
{
    char* pwd = malloc(sizeof(char) * 100);
    char* prompt = NULL;
    char** commands;

    getcwd(pwd, 100);
    if (isatty(0))
        my_printf("\033[1;34m%s\033[0m \033[1;32m~>\033[0m ", \
        get_current_dir(pwd));
    prompt = get_command();
    commands = parse_str(prompt, ';');
    for (int i = 0; commands[i]; i++) {
        shell->command = parse_args(clean_str(commands[i]));
        dispatch_cmd(shell);
    }
    free(pwd);
}
