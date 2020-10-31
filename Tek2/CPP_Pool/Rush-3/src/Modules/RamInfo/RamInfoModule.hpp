/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamInfoModule.hpp
*/


#ifndef RAMINFOMODULE_H_
#define RAMINFOMODULE_H_


#include "../../../app/Interface/IMonitorModule.hpp"
#include "SubModules/TotalSubModule.hpp"
#include "SubModules/AvailableSubModule.hpp"

class RamInfoModule: public IMonitorModule {
    public:
        RamInfoModule();
        void refresh() override;
        const std::string & getTotal() const;
        const std::string & getAvailable() const;

    private:
        RamInfo::TotalSubModule _total;
        RamInfo::AvailableSubModule _available;
};


#endif //RAMINFOMODULE_H_
