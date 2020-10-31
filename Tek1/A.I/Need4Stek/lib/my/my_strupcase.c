/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** put letter in upcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    return (str);
}
