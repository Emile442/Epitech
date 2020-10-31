/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TotalSubModule.hpp
*/


#ifndef TOTALSUBMODULE_H_
#define TOTALSUBMODULE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace RamInfo {
    class TotalSubModule: public IMonitorSubModule {
        public:
            TotalSubModule();
            void refresh() override;

        protected:
        private:
    };
}


#endif //TOTALSUBMODULE_H_
