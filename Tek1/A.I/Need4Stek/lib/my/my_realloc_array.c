/*
** EPITECH PROJECT, 2019
** my_realloc_array
** File description:
** my_realloc_array
*/

#include "my.h"

char **my_realloc(char **old_array, int new_size)
{
    char **new_array = malloc(sizeof(char*) * (new_size + 1));

    for (int i = 0; old_array[i]; i++) {
        new_array[i] = malloc(sizeof(char) * (my_strlen(old_array[i]) + 1));
        new_array[i] = my_strcpy(new_array[i], old_array[i]);
    }
    return (new_array);
}
