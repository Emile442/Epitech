/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** prompt
*/

#include "my.h"
#include "my_shell.h"

char* get_command(void)
{
    char* buffer = NULL;
    size_t len = 0;
    int c;

    c = getline(&buffer, &len, stdin);
    if (c == -1)
        return ("exit");
    return (buffer);
}

void prompt_loop(shell_t* shell)
{
    char* pwd = malloc(sizeof(char) * 100);

    getcwd(pwd, 100);
    if (isatty(0))
        my_printf("%s ~> ", get_current_dir(pwd));
    shell->command = parse_args(get_command());
    if (shell->command[0] != NULL)
        dispatch_cmd(shell);
    free(pwd);
}
