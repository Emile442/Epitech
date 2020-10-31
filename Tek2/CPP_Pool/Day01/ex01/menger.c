/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** desc
*/

#include "menger.h"

void menger(int size, int level, int x, int y)
{
    if (size == 0 || level == 0)
        return;
    printf("%03d %03d %03d\n", (size / 3), (size / 3) + x, (size / 3) + y);
    menger(size / 3, level - 1, x, y);
    menger(size / 3, level - 1, x, y + (size / 3));
    menger(size / 3, level - 1, x, y + 2 * (size / 3));
    menger(size / 3, level - 1, x + (size / 3), y);
    menger(size / 3, level - 1, x + (size / 3), y + 2 * (size / 3));
    menger(size / 3, level - 1, x + 2 * (size / 3), y);
    menger(size / 3, level - 1, x + 2 * (size / 3), y + (size / 3));
    menger(size / 3, level - 1, x + 2 * (size / 3), y + 2 * (size / 3));
}