/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** utils
*/

#include "my.h"
#include "my_ls.h"

char* get_file_path(option_t *options, char* filename)
{
    char *str = malloc(sizeof(char) * (my_strlen(options->path) + \
    my_strlen(filename) + 2));

    if (str == NULL)
        exit(EPI_FAILURE);
    my_memset(str, '\0', my_strlen(options->path) + my_strlen(filename) + 2);
    if (options->path[0] == '.' && options->path[1] == '\0')
        return (filename);
    my_strcpy(str, options->path);
    if (options->path[my_strlen(options->path)] != '/')
        my_strcat(str, "/");
    my_strcat(str, filename);
    return (str);
}

void my_puterror(char* str)
{
    write(2, str, my_strlen(str));
}
