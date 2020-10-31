/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsageSubModule.hpp
*/


#ifndef USAGESUBMODULE_H_
#define USAGESUBMODULE_H_

#include "../../../../app/Interface/IMonitorSubModule.hpp"

const int NUM_CPU_STATES = 10;

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

enum CPUStates {
    S_USER = 0,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

typedef struct CPUData {
    std::string cpu;
    size_t times[NUM_CPU_STATES];
} CPUData;

typedef struct CPUUsage {
    std::string nbr;
    float active;
    float idle;
} CPUUsage;

namespace CpuInfo {
    class UsageSubModule: public IMonitorSubModule {
        public:
            UsageSubModule();
            void refresh() override;
            const std::vector<CPUUsage> & getUsage() const;

        private:
            void ReadStatsCPU(std::vector<CPUData> & entries);
            size_t GetIdleTime(const CPUData & e);
            size_t GetActiveTime(const CPUData & e);
            void putStats(const std::vector<CPUData> & entries1, const std::vector<CPUData> & entries2);
            std::vector<CPUUsage> _array;

    };
}


#endif //USAGESUBMODULE_H_
