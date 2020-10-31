/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** strstr function
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    if (!str[0])
        return (0);
    for (int i = 0; to_find[i]; i++) {
        if (to_find[i] != str[i])
            return (my_strstr(str + 1, to_find));
    }
    return (str);
}