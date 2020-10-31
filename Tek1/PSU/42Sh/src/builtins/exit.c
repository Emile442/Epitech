/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** exit
*/

#include "sh.h"

char **make_exit(shell_t* shell)
{
    shell->exit = true;
    return (NULL);
}
