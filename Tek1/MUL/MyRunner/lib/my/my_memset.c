/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** My memset
*/

void *my_memset(char *str, int value, int size)
{
    for (int i = 0; str && i < size; i++)
        str[i] = value;
    return (str);
}