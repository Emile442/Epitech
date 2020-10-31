/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** get length of a string
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}
