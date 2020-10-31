/*
** EPITECH PROJECT, 2018
** my_evil_str
** File description:
** Revert string
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int i = my_strlen(str) - 1;
    int n = 0;
    char tmp;

    while (n < i) {
        tmp = str[n];
        str[n] = str[i];
        str[i] = tmp;
        n++;
        i--;
    }
    return (str);
}