/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** pre_exec
*/


#include "my_shell.h"

bool exec_c(shell_t* shell, char* bin);

char* find_exec(char** env, char* pwd, char* target)
{
    char** paths = get_env_path(env);

    if (file_exist(get_file_path(pwd, target)))
        return (get_file_path(pwd, target));
    for (int i = 0; paths[i]; i++) {
        if (file_exist(get_file_path(paths[i], target)))
            return (get_file_path(paths[i], target));
    }
    free(paths);
    return ("NOT FOUND");
}

void signal_error(int status)
{
    if (WTERMSIG(status) == SIGSEGV)
        my_printf("%s\n", ERR_SEGV);
    if (WTERMSIG(status) == SIGFPE)
        my_printf("%s\n", ERR_FPR);
}

int exec_command(shell_t* shell)
{
    char* bin = find_exec(shell->env, get_env(shell->env, "PWD"), \
    shell->command[0]);
    int status = 0;
    int pid;

    if (!check_error(shell->command[0], bin))
        return (0);
    pid = fork();
    if (pid == 0) {
        exec_c(shell, bin);
    } else {
        waitpid(0, &status, WUNTRACED);
        if (WIFSIGNALED(status))
            signal_error(status);
    }
    return (0);
}
