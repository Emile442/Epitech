/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** is my str only low case
*/

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    for (; str[i]; i++) {
        if (str[i] > 122 || str[i] < 97)
            return (0);
    }
    return (1);
}
