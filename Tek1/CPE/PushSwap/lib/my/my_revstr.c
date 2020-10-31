/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Reverse a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    char tmp;

    for (; str[i] != '\0'; i++);
    i--;
    for (int j = 0; j <= i; j++) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i--;
    }
    return (str);
}