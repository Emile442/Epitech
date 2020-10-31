/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** error
*/


#include "my_shell.h"

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
