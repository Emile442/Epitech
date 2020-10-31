/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex07
*/

#include <criterion/criterion.h>
#include "../string.h"

Test(copy, good_copy)
{
    string_t s;
    char* base = "Hello World";
    char* expected = "llo";
    char* tmp = malloc(sizeof(char) * 4);
    size_t count;

    tmp[3] = 0;
    string_init(&s, base);
    count = s.copy(&s, tmp, 3, 2);
    cr_assert_str_eq(tmp, expected);
    cr_assert(count == strlen(expected));
    free(tmp);
}

Test(copy, str_nul)
{
    string_t s;
    char* base = "Hello World";
    char* tmp = NULL;
    size_t count;

    string_init(&s, base);
    count = s.copy(&s, tmp, 3, 2);
    cr_assert(count == 0);
    free(tmp);
}

Test(copy, str_str_nul)
{
    string_t s;
    char* base = NULL;
    char* tmp = malloc(sizeof(char) * 4);
    size_t count;

    string_init(&s, base);
    count = s.copy(&s, tmp, 3, 2);
    cr_assert(count == 0);
    free(tmp);
}
