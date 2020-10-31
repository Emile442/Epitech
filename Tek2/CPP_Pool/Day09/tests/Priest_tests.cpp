/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Priest_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Priest.hpp"

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

Test(Priest, new) {
    OSRedirector oss(std::cout);

    Priest p("poney", 42);
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey enters in the order\n");
}

Test(Priest, CloseAttack) {
    OSRedirector oss(std::cout);
    Priest p("poney", 42);
    int got = p.CloseAttack();
    
    cr_assert(got == 10 + 21);
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey enters in the order\nponey uses a spirit explosion\n");
    cr_assert(p.getPower() == 90);
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    p.CloseAttack();
    got = p.CloseAttack();
    cr_assert(got == 0);
    //cr_assert_eq(oss.getContent(), "poney Created\nponey enters in the order\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey uses a spirit explosion\nponey out of power");
}

Test(Priest, Heal)
{
    OSRedirector oss(std::cout);
    Priest p("poney", 42);

    p.TakeDamage(80);
    cr_assert(p.getPv() == 20);
    p.Heal();
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey enters in the order\nponey takes 80 damage\nponey casts a little heal spell\n");
    cr_assert(p.getPv() == 90);
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    p.Heal();
    cr_assert(p.getPv() == 100);
    p.TakeDamage(33);
    p.Heal();
    cr_assert(p.getPv() == 67);
}