/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Return true if string was a int, else false
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}