/*
** EPITECH PROJECT, 2019
** test_check_map
** File description:
** tests the check map functions
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(check_file_errors, valid_content)
{
    char *cont[] = {"2:C1:C2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};

    cr_assert(!check_file_errors(cont));
}

Test(check_file_errors, invalid_content)
{
    char **cont;
    char **cont2;

    cont = malloc(sizeof(char *) * 5);
    cont[0] = my_strdup("2:C1:C2");
    cont[1] = "3:D4:F4";
    cont[2] = "4:D3:F4";
    cont[3] = "5:D4:F4";
    cont[4] = NULL;
    cr_assert(check_file_errors(cont));
    cont2 = malloc(sizeof(char *) * 5);
    cont2[0] = my_strdup("2:C1:C2");
    cont2[1] = "3:D4:F4";
    cont2[2] = "4:D3:F";
    cont2[3] = "5:D4:F4";
    cont2[4] = NULL;
    cr_assert(check_file_errors(cont2));
}

Test(check_file_errors, invalid_content2)
{
    char **cont;

    cont = malloc(sizeof(char *) * 3);
    cont[0] = my_strdup("2:C1:C2");
    cont[1] = "3:D4:F4";
    cont[2] = NULL;
    cr_assert(check_file_errors(cont));
}

Test(check_file_errors, malloc_failed)
{
    cr_assert(check_file_errors(NULL));
}
