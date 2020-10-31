/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#ifndef CPP_D07M_2019_OSREDIRECTION_HPP
#define CPP_D07M_2019_OSREDIRECTION_HPP

#include <ostream>
#include <iostream>
#include <criterion/criterion.h>

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

#endif //CPP_D07M_2019_OSREDIRECTION_HPP
