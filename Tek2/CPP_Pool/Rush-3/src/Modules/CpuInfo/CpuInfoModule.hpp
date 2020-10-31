/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CpuInfoModule.hpp
*/


#ifndef CPUINFOMODULE_H_
#define CPUINFOMODULE_H_


#include "../../../app/Interface/IMonitorModule.hpp"
#include <vector>
#include "SubModules/UsageSubModule.hpp"

class CpuInfoModule: public IMonitorModule {
    public:
        CpuInfoModule();
        void refresh() override;
        const std::vector<CPUUsage> & getUsage() const;

    private:
        CpuInfo::UsageSubModule _usage;
};


#endif //CPUINFOMODULE_H_
