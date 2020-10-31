/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsernameSubModule.hpp
*/


#ifndef HOSTINFO_USERNAMESUBMODULE_H_
#define HOSTINFO_USERNAMESUBMODULE_H_


#include<iostream>
#include <cstdio>
#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace HostInfo{
    class UsernameSubModule: public IMonitorSubModule {
        public:
            UsernameSubModule();
            void refresh() override;

        private:
    };

}


#endif //HOSTINFO_USERNAMESUBMODULE_H_
