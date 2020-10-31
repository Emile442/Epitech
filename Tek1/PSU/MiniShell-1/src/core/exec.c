/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exec
*/

#include "my.h"
#include "my_shell.h"

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

bool check_error(char* cmd, char* path)
{
    struct stat s;

    if (my_strcmp(path, "NOT FOUND") == 0) {
        my_printf("%s: %s\n", cmd, ERR_CMD_NTF);
        return (false);
    }
    stat(path, &s);
    if (S_ISDIR(s.st_mode) && (path[0] == '/' || \
    (path[0] == '.' && path[1] == '/'))) {
        my_printf("%s: %s\n", cmd, ERR_PERM);
        return (false);
    }
    if (S_ISDIR(s.st_mode)) {
        my_printf("%s: %s D\n", cmd, ERR_CMD_NTF);
        return (false);
    }
    return (true);
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
        if ((execve(bin, &shell->command[0], shell->env)) == -1)
            my_printf("%s: %s\n", shell->command[0], ERR_FORMAT);
    } else {
        waitpid(0, &status, WUNTRACED);
        if (WIFSIGNALED(status))
            signal_error(status);
    }
    return (0);
}
