/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find str in another str
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    for (; to_find[i] && str[0]; i++) {
        if (to_find[i] != str[i])
            return (my_strstr((str + 1), to_find));
    }
    if (str[i] == '\0')
        return (NULL);
    return (str);
}
