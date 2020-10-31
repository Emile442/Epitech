/*
** EPITECH PROJECT, 2018
** my sort int array
** File description:
** sort array of int
*/

#include "my.h"

int is_sorted(int *array, int size)
{
    int i = 0;

    while (i < (size - 1)) {
        if (array[i] > array[i + 1])
            return (1);
        i++;
    }
    return (0);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int sorted = -1;

    while (sorted != 0) {
        sorted = is_sorted(array, size);
        if (array[i] > array[i + 1])
            my_swap(&array[i], &array[i + 1]);
        if (i == size - 2)
            i = -1;
        i++;
    }
}
