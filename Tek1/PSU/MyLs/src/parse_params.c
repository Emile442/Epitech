/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** parse_params
*/

#include "my.h"
#include "my_ls.h"

static void check_flag(option_t* options, char* str)
{
    for (int i = 1; str[i]; i++) {
        if (str[i] == 'l')
            options->l_l = true;
        if (str[i] == 't')
            options->t = true;
        if (str[i] == 'r')
            options->r = true;
        if (str[i] == 'd')
            options->d = true;
        if (str[i] == 'R')
            options->r_r = true;
    }
}

option_t* parse_params(char* path, char** params, bool print_path)
{
    option_t* options = malloc(sizeof(option_t));

    if (options == NULL)
        exit(EPI_FAILURE);
    options->path = path;
    options->tt_block = 0;
    options->print_path = print_path;
    options->l_l = false;
    options->t = false;
    options->r = false;
    options->d = false;
    options->r_r = false;
    for (int i = 1; params[i]; i++) {
        if (params[i][0] == '-') {
            check_flag(options, params[i]);
        }
    }
    return (options);
}
