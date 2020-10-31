/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** capitalize every word
*/

int is_lowcase(char c)
{
    if (c > 96 && c < 123)
        return (1);
    return (0);
}

int is_upcase(char c)
{
    if (c > 64 && c < 91)
        return (1);
    return (0);
}

int is_alpha_num(char c)
{
    if ((c > 47 && c < 58) || (c > 64 && c < 91)
        || (c > 96 && c < 123))
        return (1);
    return (0);
}

int is_first(char *str, int i)
{
    if (is_alpha_num(str[i - 1]) == 1)
        return (0);
    if (is_lowcase(str[i]) == 1)
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str[0] > 96 && str[0] < 123)
        str[0] -= 32;
    for (; str[i]; i++) {
        if (is_first(str, i) == 1)
            str[i] -= 32;
        if (is_alpha_num(str[i - 1]) == 1
        && is_upcase(str[i]) == 1) {
            str[i] += 32;
        }
    }
    return (str);
}
