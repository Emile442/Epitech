/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** detect_char
*/

int detec_char(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}
