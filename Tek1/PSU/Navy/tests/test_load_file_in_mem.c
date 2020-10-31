/*
** EPITECH PROJECT, 2019
** load file in mem
** File description:
** load file in mem test file
*/

#include <criterion/criterion.h>
#include "my.h"
#include "navy.h"
#include <unistd.h>

Test(load_file_in_mem, invalid_filepath)
{
    cr_assert_null(load_file_in_mem("oui"));
}

Test(load_file_in_mem, valid_filepath)
{
    char *content = load_file_in_mem("test1");

    cr_assert_str_eq(content, "this is a test");
}

Test(load_file_in_mem, valid_path_to_dir)
{
    char *content = load_file_in_mem(".");

    cr_assert_null(content);
}

Test(load_file_in_2d_array, valid_filepath)
{
    char **content = load_file_in_2d_array("test2");

    cr_assert_str_eq(content[0], "Bonjour");
    cr_assert_str_eq(content[1], "Oui");
    cr_assert_str_eq(content[2], "Parfois");
    cr_assert_null(content[3]);
}
