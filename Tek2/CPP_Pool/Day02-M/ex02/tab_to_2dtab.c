/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** Ex02
*/

#include <stdlib.h>

void tab_to_2dtab(const int* tab, int length, int width, int*** res)
{
    int tmp = 0;

    *(res) = malloc(length * sizeof(int *));
    if (*(res) == NULL)
        return;
    for (int i = 0; i < length; i++) {
        (*res)[i] = malloc(width * sizeof(int));
        if ((*res)[i] == NULL)
            return;
    }
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++, tmp++)
            (*res)[i][j] = tab[tmp];
}
