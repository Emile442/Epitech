/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NameSubModule.hpp
*/


#ifndef OSINFO_NAMESUBModule_H_
#define OSINFO_NAMESUBModule_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace OSInfo {
    class NameSubModule: public IMonitorSubModule{
        public:
            NameSubModule();
            void refresh() override;
    };
}


#endif //OSINFO_NAMESUBModule_H_
