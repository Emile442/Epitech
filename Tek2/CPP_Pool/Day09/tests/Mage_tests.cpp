/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Mage_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Mage.hpp"

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

Test(Mage, new) {
    OSRedirector oss(std::cout);

    Mage m("poney", 42);
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\n");
}

Test(Mage, RangeAttack) {
    OSRedirector oss(std::cout);
    Mage m("poney", 42);
    int got = m.RangeAttack();

    cr_assert(got == 20 + 11);
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey launches a fire ball\n");
    cr_assert(m.getPower() == 75);
    m.RangeAttack();
    m.RangeAttack();
    m.RangeAttack();
    m.RangeAttack();
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey launches a fire ball\nponey launches a fire ball\nponey launches a fire ball\nponey launches a fire ball\nponey out of power\n");
}

Test(Mage, CloseAttack) {
    OSRedirector oss(std::cout);
    Mage m("poney", 42);
    int got = m.CloseAttack();

    cr_assert(got == 0);
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey blinks\n");
    cr_assert(m.getPower() == 90);
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    m.CloseAttack();
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey blinks\nponey out of power\n");
}

Test(Mage, RestorePower) {
    OSRedirector oss(std::cout);
    Mage m("poney", 42);

    m.RangeAttack();
    m.RangeAttack();
    m.RangeAttack();
    cr_assert(m.getPower() == 25);
    m.RestorePower();
    cr_assert_eq(oss.getContent(), "poney Created\nponey teleported\nponey launches a fire ball\nponey launches a fire ball\nponey launches a fire ball\nponey takes a mana potion\n");
    cr_assert(m.getPower() == 25 + 50 + 12);
    m.RestorePower();
    cr_assert(m.getPower() == 100);
}