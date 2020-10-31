/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorSubModule.hpp
*/

#ifndef I_MONITORSUBMODULE_H_
#define I_MONITORSUBMODULE_H_

#include <string>

class IMonitorSubModule {
    public:
        IMonitorSubModule(const std::string & name);
        virtual ~IMonitorSubModule() = 0;
        virtual void refresh() = 0;
        virtual void init();
        virtual const std::string & getName() const;
        virtual const std::string & getValue() const;

    protected:
        std::string _name;
        std::string _value;
};


#endif //I_MONITORSUBMODULE_H_
