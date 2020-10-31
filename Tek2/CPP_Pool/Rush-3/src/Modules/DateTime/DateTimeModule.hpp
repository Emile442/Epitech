/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateTimeModule.hpp
*/


#ifndef DATETIMEMODULE_H_
#define DATETIMEMODULE_H_

#include "../../../app/Interface/IMonitorModule.hpp"
#include "SubModules/DateSubModule.hpp"
#include "SubModules/TimeSubModule.hpp"

class DateTimeModule: public IMonitorModule {
    public:
        DateTimeModule();
        void refresh() override;
        const std::string & getDate() const;
        const std::string & getTime() const;

    private:
        DateTime::DateSubModule _date;
        DateTime::TimeSubModule _time;
};


#endif //DATETIMEMODULE_H_
