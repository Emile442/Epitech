/*
** EPITECH PROJECT, 2018
** map_init
** File description:
** Map Init
*/

#include "my.h"
#include "my_runner.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

bool map_init(window_t *current, char* filepath)
{
    FILE *fp = fopen(filepath, "r");
    char* line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return (false);
    getline(&line, &len, fp);
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == 'O')
            push_list(&current->waiting, 1);
        else if (line[i] == 'x')
            push_list(&current->waiting, 0);
    reverse_list(&current->waiting);
    return (true);
}
