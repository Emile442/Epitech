/*
** EPITECH PROJECT, 2018
** concat_params
** File description:
** Print Params
*/

#include "include/my.h"
#include <stdlib.h>

char *concat_params(int argc, const char **args)
{
    char *tmp;

    tmp = malloc(sizeof(char *) * (argc + 1));
    for (int i = 0; i < argc; i++) {
        tmp = my_strcat(tmp, args[i]);
        tmp = my_strcat(tmp, "\n");
    }
    return (my_strcat(tmp, "\0"));
}