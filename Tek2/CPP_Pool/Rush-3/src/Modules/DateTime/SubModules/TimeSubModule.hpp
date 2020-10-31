/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TimeSubModule.hpp
*/


#ifndef DATETIME_TIMESUBMODULE_H_
#define DATETIME_TIMESUBMODULE_H_

#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace DateTime {
    class TimeSubModule: public IMonitorSubModule {
        public:
            TimeSubModule();
            void refresh() override;

    };
}


#endif //DATETIME_TIMESUBMODULE_H_
