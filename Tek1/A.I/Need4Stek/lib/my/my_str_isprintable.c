/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** is my str only printable characters
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    for (; str[i]; i++) {
        if (str[i] < 32 || str[i] > 255)
            return (0);
    }
    return (1);
}
