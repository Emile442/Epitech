/*
** EPITECH PROJECT, 2019
** My library
** File description:
** My str is alpha file
*/

#include <my.h>

int my_str_isalpha(char const *str)
{
    int state = 1;

    if (!my_strlen(str))
        state = 0;
    for (int i = 0; str[i] && state; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            state = 0;
    return (state);
}

char *my_strlowercase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}

char *my_struppercase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}

int my_str_isalphanum(char const *str)
{
    int state = 1;

    if (!my_strlen(str))
        state = 0;
    for (int i = 0; str[i] && state; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] < '0' || str[i] > '9'))
            state = 0;
    return (state);
}
