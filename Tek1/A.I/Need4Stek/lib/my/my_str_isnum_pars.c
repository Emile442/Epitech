/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my_str_isnum_pars_1
*/

int my_str_isnum_pars(char const *str, char c)
{
    int i = 0;

    if (str == "")
        return (1);
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && str[i] != c)
            return (0);
        i++;
    }
    return (1);
}
