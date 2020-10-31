/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UpSubModule.hpp
*/


#ifndef NETWORK_UPSUBMODULE_H_
#define NETWORK_UPSUBMODULE_H_

#include <string>
#include <fstream>
#include <iostream>
#include "../../../../app/Interface/IMonitorSubModule.hpp"


namespace NetworkInfo {
    class UpSubModule: public IMonitorSubModule {
        public:
            UpSubModule();
            void refresh() override;
    };
}


#endif //NETWORK_UPSUBMODULE_H_
