/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** echo
*/

#include "sh.h"

char **make_echo(shell_t* shell)
{
    char* tmp = NULL;
    int len = 0;
    int st = 0;

    if (my_strcmp(shell->command[1], "-n"))
        st = 1;
    for (int i = 1 + st; shell->command[i]; i++, len++);
    tmp = malloc(sizeof(char) * len + 1);
    strcpy(tmp, shell->command[1 + st]);
    for (int i = 2 + st; shell->command[i]; i++) {
        strcat(tmp, " ");
        strcat(tmp, shell->command[i]);
    }
    if (!st)
        printf("%s\n", tmp);
    else {
        printf("%s", tmp);
        fflush(0);
    }
    return (shell->env);
}
