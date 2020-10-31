/*
** EPITECH PROJECT, 2018
** my_params_to_array
** File description:
** Params to array
*/

#include "my.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *tmp;

    tmp = malloc(sizeof(struct info_param*) * (ac + 1));
    if (tmp == NULL)
        return (0);
    for (; i < ac; i++){
        tmp[i].length = my_strlen(av[i]);
        tmp[i].str = av[i];
        tmp[i].copy = my_strdup(av[i]);
        tmp[i].word_array = my_str_to_word_array(av[i]);
    }
    tmp[i].str = NULL;
    return (tmp);
}