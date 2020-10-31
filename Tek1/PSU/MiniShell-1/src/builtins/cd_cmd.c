/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd_cmd
*/

#include "my.h"
#include "my_shell.h"

#include <sys/types.h>
#include <sys/stat.h>

int cd_error(char* target)
{
    if (my_strcmp(target, "") == 0 || my_strcmp(target, "~") == 0)
        return (0);
    if (my_strcmp(target, "-") == 0)
        return (0);
    if (access(target, F_OK) == -1) {
        my_printf("%s: No such file or directory.\n", target);
        return (1);
    }
    if (!is_directory(target)) {
        my_printf("%s: Not a directory.\n", target);
        return (1);
    }
    return (0);
}

void set_path(shell_t* shell, char* new)
{
    char* pwd = malloc(sizeof(char) * 1000);
    char* old = malloc(sizeof(char) * 1000);

    getcwd(old, 1000);
    chdir(new);
    getcwd(pwd, 1000);
    shell->env = edit_env(shell->env, "PWD", pwd);
    shell->env = edit_env(shell->env, "OLDPWD", old);
}

int cd_cmd(shell_t* shell)
{
    char* old = get_env(shell->env, "OLDPWD");
    char* new_pwd = shell->command[1];
    char* home = get_env(shell->env, "HOME");

    if (cd_error(shell->command[1]))
        return (1);
    if (my_strcmp(shell->command[1], "") == 0 || \
        my_strcmp(shell->command[1], "~") == 0)
        set_path(shell, home);
    else if (my_strcmp(shell->command[1], "-") == 0) {
        set_path(shell, old);
    } else
        set_path(shell, new_pwd);
    return (0);
}
