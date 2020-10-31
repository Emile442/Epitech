/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** validation
*/

#include "my.h"
#include "my_shell.h"

int my_str_correct_env(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (my_str_isalpha(&str[i]) == 1 && my_str_isnum(&str[i]) ==1) {
            return (0);
        }
    return (1);
}
