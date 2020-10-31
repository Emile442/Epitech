/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** main
*/

#include "my.h"
#include "my_ls.h"

int count_path(char** params)
{
    int path_found = 0;

    for (int i = 1; params[i]; i++)
        if (params[i][0] != '-')
            path_found++;
    return (path_found);
}

static void print_blank_line(int nbr, int total)
{
    if (nbr != total)
        my_printf("\n");
}

int main(int ac, char **av)
{
    option_t* options = NULL;
    int path_found = count_path(av);
    int tmp = 0;

    (void)ac;
    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-') {
            tmp++;
            options = parse_params(av[i], av, path_found > 1);
            my_ls(options);
            print_blank_line(tmp, path_found);
            free(options);
        }
    }
    if (path_found == 0) {
        options = parse_params(".", av, false);
        my_ls(options);
        free(options);
    }
    return (0);
}
