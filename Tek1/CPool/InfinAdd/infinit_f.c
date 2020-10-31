/*
** EPITECH PROJECT, 2018
** infinit_f
** File description:
** Infinit Function
*/

#include <stdlib.h>
#include "my.h"

int mode(char const *a, char const *b)
{
    if (a[0] == '-' && b[0] == '-')
        return (3);
    if (a[0] == '-' && b[0] != '-')
        return (1);
    if (a[0] != '-' && b[0] == '-')
        return (2);
    return (0);
}

int size(char const *a, char const *b)
{
    int len1 = my_strlen(a);
    int len2 = my_strlen(b);

    if (len1 > len2) {
        return (len1);
    } else if (len1 < len2) {
        return (len2);
    }
}

char *c_to_p(const char *c)
{
    char *tmp1 = malloc(sizeof(char) * my_strlen(c));
    char *tmp = malloc(sizeof(char) * my_strlen(c));
    char *trim = malloc(sizeof(char) * my_strlen(c));
    int j = 0;

    my_strncpy(tmp1, c, my_strlen(c));
    my_strncpy(tmp, my_revstr(tmp1), my_strlen(c));
    for (int i = 0; i < my_strlen(c); i++) {
        if (tmp[i] != '-') {
            j = my_strlen(trim);
            trim[j] = tmp[i];
        }
    }
    trim[j + 1] = '\0';
    return (my_revstr(trim));
}

char *add_sign(const char *c)
{
    char *tmp1 = malloc(sizeof(char) * my_strlen(c));
    char *tmp = malloc(sizeof(char) * my_strlen(c));
    char *trim = malloc(sizeof(char) * my_strlen(c));
    int j = 0;

    my_strncpy(tmp1, c, my_strlen(c));
    my_strncpy(tmp, my_revstr(tmp1), my_strlen(c));
    for (int i = 0; i < my_strlen(c); i++) {
        j = my_strlen(trim);
        trim[j] = tmp[i];
    }
    trim[j + 1] = '-';
    trim[j + 2] = '\0';
    return (my_revstr(trim));
}