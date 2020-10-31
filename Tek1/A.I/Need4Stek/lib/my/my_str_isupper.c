/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** is my str only upper case
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    for (; str[i]; i++) {
        if (str[i] < 65 || str[i] > 90)
            return (0);
    }
    return (1);
}
