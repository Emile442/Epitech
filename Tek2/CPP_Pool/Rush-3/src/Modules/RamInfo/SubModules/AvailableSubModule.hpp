/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** AvailableSubModule.hpp
*/


#ifndef AVAILABLESUBMODULE_H_
#define AVAILABLESUBMODULE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace RamInfo {
    class AvailableSubModule: public IMonitorSubModule {
        public:
            AvailableSubModule();
            void refresh() override;

        protected:
        private:
    };
}


#endif //AVAILABLESUBMODULE_H_
