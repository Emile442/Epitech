/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** Display in ASC order an array
*/

void my_swap(int *a , int *b);

void swap(int *c, int *d)
{
    if (*c > *d)
        my_swap(c, d);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    while (i <= size) {
        while (j < size - i - 1) {
            swap(&array[j], &array[j + 1]);
            j++;
        }
        i++;
    }
}