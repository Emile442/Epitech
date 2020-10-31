/*
** EPITECH PROJECT, 2018
** match
** File description:
** Match - nmmatch - [match]
*/

#include "my.h"

int	match(char const *s1, char const *s2)
{
    if (*s1 == 0 && *s2 == 0)
        return (1);
    if (*s1 == *s2)
        return (match(s1+ 1, s2 + 1));
    if (*s1 != 0 && *s2 == '*')
        return (match(s1, s2 + 1) || match(s1 + 1, s2));
    if (*s1 == 0 && *s2 == '*')
        return (match(s1, s2 + 1));
    return (0);
}