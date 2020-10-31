/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** parsing
*/

#include "my_shell.h"


char** parse_args(char* str)
{
    char** cmd_array = my_str_to_word_array(str);

    return (cmd_array);
}
