/*
** EPITECH PROJECT, 2020
** server
** File description:
** rfc_str
*/

#include "my_teams.h"

char* rfc_str(int code, char* str)
{
    char code_str[5];
    char* rt;

    memset(code_str, '\0', 5);
    sprintf(code_str, "%d", code);
    rt = calloc(strlen(str) + strlen(code_str) + 3, sizeof(char));
    strcat(rt, code_str);
    strcat(rt, " ");
    strcat(rt, str);
    strcat(rt, "\r\n");
    return (rt);
}
