/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** revstr
*/

char *my_revstr(char *str)
{
    int j = 0;
    char c;

    for (; str[j + 1]; j++);
    for (int i = 0; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return (str);
}
