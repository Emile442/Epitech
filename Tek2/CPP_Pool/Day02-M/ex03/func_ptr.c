/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** Ex03
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "func_ptr.h"

void print_normal(const char* str)
{
    printf("%s\n", str);
}

void print_reverse(const char* str)
{
    char* rev = malloc(sizeof(char) * strlen(str) + 1);

    for (size_t i = 0, j = strlen(str) - 1; i < strlen(str); i++, j--)
        rev[i] = str[j];
    printf("%s\n", rev);
}

void print_upper(const char* str)
{
    for (int i = 0; str[i]; i++)
        printf("%c", toupper(str[i]));
    printf("\n");
}

void print_42(const char* str)
{
    printf("42\n");
}

void (*do_op[4])(const char*) =
{
    print_normal,
    print_reverse,
    print_upper,
    print_42
};

void do_action(action_t action, const char* str)
{
    do_op[action](str);
}
