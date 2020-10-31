/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias/unalias
*/

#include "sh.h"

char** make_unalias(shell_t* shell)
{
    search_list(&shell->alias, shell->command[1]);
    pull_list(&shell->alias);
    return (shell->env);
}
