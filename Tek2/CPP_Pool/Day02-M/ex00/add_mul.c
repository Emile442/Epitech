/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** desc
*/

void add_mul_4param(int first, int second, int *add, int *mul)
{
    *add = first + second;
    *mul = first * second;
}

void add_mul_2param(int* first, int* second)
{
    int tmp = *first;

    *first += *second;
    *second *= tmp;
}

