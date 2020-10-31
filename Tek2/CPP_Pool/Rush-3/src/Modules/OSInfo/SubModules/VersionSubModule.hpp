/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** VersionSubModule.hpp
*/


#ifndef OSINFO_VERSIONSUBMODULE_H_
#define OSINFO_VERSIONSUBMODULE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace OSInfo {
    class VersionSubModule: public IMonitorSubModule {
        public:
            VersionSubModule();
            void refresh() override;
        private:
    };
}


#endif //OSINFO_VERSIONSUBMODULE_H_
