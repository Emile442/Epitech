/*
** EPITECH PROJECT, 2020
** server
** File description:
** error_handling
*/

#include "my_teams.h"

bool is_number(const char* str)
{
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

bool has_error(const int ac, const char** av)
{
    if (ac == 2) {
        if (strcmp(av[1], "--help") == 0) {
            print_help();
            return (true);
        }
    }
    if (ac == 3) {
        if (!is_number(av[2]))
            return (true);
        return (false);
    }
    return (true);
}
