/*
** EPITECH PROJECT, 2019
** my-exec
** File description:
** main
*/

#include "my.h"
#include "my_shell.h"

void signag_intercept(int handler)
{
    (void)handler;
    my_printf("\n");
}

int main(int ac, char **av, char **env)
{
    shell_t* shell = init_shell(env);
    int code = 0;

    (void)ac;
    (void)av;
    signal(SIGINT, signag_intercept);
    while (!shell->exit)
        prompt_loop(shell);
    code = shell->code;
    free(shell);
    return (code);
}
