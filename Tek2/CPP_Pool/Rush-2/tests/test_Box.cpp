/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Box.hpp"
/*#include "OSRedirection.hpp"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
};*/

Test(Box, Constructor_wrap_box_is_open) {
    Wrap p;
    Box b;

    cr_assert_eq(false, b.BoxIsOpen());
}

Test(Box, Box_close_me) {
    Wrap p;
    Box b;
    bool test = true;

    b.CloseMe();
    test = b.BoxIsOpen();
    cr_assert_eq(false, test);
}