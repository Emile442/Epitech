/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** free_double_char
*/

#include "my_shell.h"

void free_double_char(char** array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
