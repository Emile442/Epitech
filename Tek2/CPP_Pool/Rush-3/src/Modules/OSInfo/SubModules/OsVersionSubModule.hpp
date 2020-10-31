/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OsVersionSubModule.hpp
*/


#ifndef OSINFO_OSVERSIONSUBMODULE_H_
#define OSINFO_OSVERSIONSUBMODULE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace OSInfo {
    class OsVersionSubModule: public IMonitorSubModule {
        public:
            OsVersionSubModule();
            void refresh() override;

        protected:
        private:
    };
}


#endif //OSINFO_OSVERSIONSUBMODULE_H_
