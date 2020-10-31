/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Teddy.hpp"
#include "OSRedirection.hpp"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
};

Test(Teddy, Teddy_is_taken, .init = redirect_all_std) {
    Teddy t("Name_t");
    OSRedirector oss(std::cout);

    t.isTaken();
    cr_assert_eq("gra hu\n", oss.getContent());
}