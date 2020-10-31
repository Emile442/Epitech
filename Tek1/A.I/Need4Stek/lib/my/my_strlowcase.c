/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** put every letter in low case
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    return (str);
}
