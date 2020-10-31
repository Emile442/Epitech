/*
** EPITECH PROJECT, 2018
** lib_my_str_isnum
** File description:
** my str isnum for libraries
*/

#include <my.h>

int my_str_isnum(char const *str)
{
    int state = 0;

    if (!my_strlen(str))
        return (1);
    for (int i = 0; str[i] != 10 && str[i] && !state; i++) {
        if (str[i] < '0' || str[i] > '9')
            (i != 0 || str[i] != '-') ? state = 1 : 0;
    }
    return (state);
}

int my_str_isposnum(char const *str)
{
    int state = 0;

    if (!*str)
        return (1);
    for (int i = 0; str[i] && !state && str[i] != 10; i++) {
        if (str[i] < '0' || str[i] > '9')
            state = 1;
    }
    return (state);
}

int my_str_isdouble(char const *str)
{
    int state = 0;
    int count = 0;

    for (int i = 0; str[i] && !state; i++)
        if (str[i] == '.')
            count++;
        else if ((str[i] < '0' || str[i] > '9') && (i != 0 || str[i] != '-'))
            state = 1;
    if (count > 1)
        state = 1;
    return (state);
}
