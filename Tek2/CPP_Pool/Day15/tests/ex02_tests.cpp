/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex01_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "ex02.hpp"

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;


    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

// OSRedirector oss(std::cout);
// cr_assert_eq(oss.getContent(), "assert");

Test(ex02, template_min)
{
    OSRedirector oss(std::cout);
    int a = 3;
    int b = 9;

    cr_assert(::min(b, a) == 3);
    cr_assert_eq(oss.getContent(), "non-template min\n");
}

Test(ex02, non_template_min)
{
    OSRedirector oss(std::cout);
    const char* a = "chaine1";
    const char* b = "chaine2";

    cr_assert(std::strcmp(::min(a, b), a) == 0);
    cr_assert_eq(oss.getContent(), "template min\n");
}

Test(ex02, template_array_min)
{
    OSRedirector oss(std::cout);
    int tab[2] = {3, 0};
    int number = templateMin(tab, 2);

    cr_assert(number == 0);
    cr_assert_eq(oss.getContent(), "template min\n");
}


Test(ex02, non_template_array_min)
{
    OSRedirector oss(std::cout);
    int tab[2] = {3, 0};
    int number = nonTemplateMin(tab, 2);

    cr_assert(number == 0);
    cr_assert_eq(oss.getContent(), "non-template min\n");
}