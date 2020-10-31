/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** core/exec
*/

#include "sh.h"

int is_exec_file(char *file)
{
    struct stat st;

    lstat(file, &st);
    if (S_ISREG(st.st_mode))
        return (1);
    if (S_ISCHR(st.st_mode))
        return (1);
    dprintf(2, "%s: %s.\n", file, ERR_PERM);
    return (0);
}

char *find_simple_cmd(char *str)
{
    int state = 1;
    int tmp = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            tmp++;
    if (tmp == 0) {
        dprintf(2, "%s: %s.\n", str, ERR_CMD_NTF);
        return (NULL);
    }
    if (access(str, X_OK) == -1)
        state = 0;
    if (!state) {
        if (access(str, F_OK) == 0)
            dprintf(2, "%s: %s.\n", str, ERR_PERM);
        else
            dprintf(2, "%s: %s.\n", str, ERR_CMD_NTF);
        return (NULL);
    }
    return (str);
}

char *find_base_cmd(char *cmd, char **path)
{
    char *buffer = NULL;
    char *result = NULL;

    buffer = my_strcat("/", cmd);
    for (int i = 0, state = 1; path[i] && state; i++)
        if ((state = access(my_strcat(path[i], buffer), X_OK)) == 0
            && is_exec_file(my_strcat(path[i], buffer)))
            (state = 0, result = my_strcat(path[i], buffer));
    return (result);
}

char *get_cmd(char *cmd, char **path)
{
    char *final_cmd = NULL;

    if (path == NULL) {
        printf("%s: %s.\n", cmd, ERR_CMD_NTF);
        return (NULL);
    }
    if ((access(cmd, X_OK) == 0) && (!is_exec_file(cmd)))
        return (NULL);
    final_cmd = find_base_cmd(cmd, path);
    if (!final_cmd)
        final_cmd = find_simple_cmd(cmd);
    return (final_cmd);
}

int execute_cmd(shell_t* shell, char **path)
{
    char *cmd = NULL;
    char** av = shell->command;
    char** env = shell->env;
    pid_t child;
    int status;

    if (!(cmd = get_cmd(av[0], path)))
        return (-1);
    av[0] = cmd;
    if ((child = fork())) {
        (wait(&status), print_child_error(status));
    } else if (child == 0) {
        if (execve(cmd, av, env) == -1) {
            (print_error(cmd), exit(-1));
        }
        exit(1);
    }
    return (0);
}
