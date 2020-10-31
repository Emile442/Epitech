/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex03
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !this->str || !ap || !ap->str)
        return;
    return (append_c(this, ap->str));
}

void append_c(string_t *this, const char *ap)
{
    char* tmp = NULL;

    if (!this || !this->str || !ap)
        return;
    this->str = realloc(this->str, sizeof(char) * strlen(this->str) + \
    strlen(ap) + 1);
    strcat(this->str, ap);
    free(tmp);
}
