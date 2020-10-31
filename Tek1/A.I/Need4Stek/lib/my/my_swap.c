/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swap 2 int
*/

void my_swap(int *a, int *b)
{
    int temp = (*a);

    (*a) = (*b);
    (*b) = temp;
}
