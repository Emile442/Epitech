/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** auth.c
*/

#include <criterion/criterion.h>

#include "my_teams.h"


Test(parsing_commands, basic_1)
{
    const char *str = "send \"USER-484-NAME\" \"Salut tu vas bien ? Moi ça.\"";

    cr_assert_str_eq(command_parsing(str)[0], "send");
    cr_assert_str_eq(command_parsing(str)[1], "USER-484-NAME");
    cr_assert_str_eq(command_parsing(str)[2], "Salut tu vas bien ? Moi ça.");
}

Test(parsing_commands, basic_2)
{
    const char *str = "uploading \"BIG-FILE.tar.gz\" \"HisNameHere\"";

    cr_assert_str_eq(command_parsing(str)[0], "uploading");
    cr_assert_str_eq(command_parsing(str)[1], "BIG-FILE.tar.gz");
    cr_assert_str_eq(command_parsing(str)[2], "HisNameHere");
}

Test(parsing_commands, basic_3)
{
    const char *str = "logout\r\n";

    cr_assert_str_eq(command_parsing(str)[0], "logout");
}

Test(parsing_commands, basic_4)
{
    const char *str = "logout\n";

    cr_assert_str_eq(command_parsing(str)[0], "logout");
}

Test(parsing_commands, basic_5)
{
    const char *str = "logout\r";

    cr_assert_str_eq(command_parsing(str)[0], "logout");
}
