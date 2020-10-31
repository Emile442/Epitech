/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** utils/str_with_num
*/

#include "my_defender.h"

char* str_with_num(char* const str, int const nbr)
{
    char* tmp = malloc(sizeof(char) * 150);

    my_memset(tmp, '\0', 150);
    my_strcpy(tmp, str);
    my_strcat(tmp, int_to_str(nbr));
    return (tmp);
}
