/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DownSubModule.hpp
*/


#ifndef DOWNSUBMODULE_H_
#define DOWNSUBMODULE_H_

#include <string>
#include <fstream>
#include <iostream>
#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace NetworkInfo {
    class DownSubModule: public IMonitorSubModule {
        public:
            DownSubModule();
            void refresh() override;

        private:
    };
}


#endif //DOWNSUBMODULE_H_
