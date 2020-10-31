/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** Return true if string was in uppercase, else false
*/

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 65 || str[i] > 90)
            return (0);
    return (1);
}