/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NameSubModule.hpp
*/


#ifndef HOSTINFO_NAMESUBModule_H_
#define HOSTINFO_NAMESUBModule_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace HostInfo {
    class NameSubModule: public IMonitorSubModule{
        public:
            NameSubModule();
            void refresh() override;
    };
}


#endif //HOSTINFO_NAMESUBModule_H_
