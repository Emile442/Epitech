/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** Main file
*/

#include <sh.h>

shell_t* init_shell(char** env)
{
    shell_t* shell = malloc(sizeof(shell_t));

    if (!(*env))
        shell->env = init_env();
    else
        shell->env = env;
    shell->exit = false;
    shell->code = 0;
    shell->all_commands = NULL;
    shell->command = NULL;
    shell->fd_pipe = malloc(sizeof(int) * 3);
    if (!shell->fd_pipe)
        return (NULL);
    for (int i = 0; i < 3; shell->fd_pipe[i] = 0, i++);
    shell->alias = NULL;
    return (shell);
}

void signag_intercept(int handler)
{
    (void)handler;
    my_printf("\n");
}

int main(int ac, char **av, char **env)
{
    char *buffer = NULL;
    char **new_env = my_strarraycpy(env);
    shell_t* shell = init_shell(new_env);

    (void)av;
    if (ac != 1)
        return (ERROR);
    signal(SIGINT, signag_intercept);
    while (!shell->exit)
        mysh_loop(shell);
    free_dchar(new_env);
    free(shell);
    (free(buffer), my_printf("exit\n"));
    return (0);
}
