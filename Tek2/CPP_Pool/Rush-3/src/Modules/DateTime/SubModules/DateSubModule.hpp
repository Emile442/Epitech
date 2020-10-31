/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateSubModule.hpp
*/


#ifndef DATETIME_DATESUBMODULE_H_
#define DATETIME_DATESUBMODULE_H_

#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>

#include "../../../../app/Interface/IMonitorSubModule.hpp"

namespace DateTime {
    class DateSubModule: public IMonitorSubModule {
        public:
            DateSubModule();
            void refresh() override;

        protected:
        private:
    };
}


#endif //DATETIME_DATESUBMODULE_H_
