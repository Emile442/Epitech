/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule.hpp
*/

#ifndef I_MONITORMODULE_HPP_
#define I_MONITORMODULE_HPP_

#include <string>

class IMonitorModule {
    public:
        IMonitorModule();
        virtual ~IMonitorModule() = 0;
        virtual void refresh() = 0;

    protected:
        std::string _name;
};

#endif //I_MONITORMODULE_HPP_
