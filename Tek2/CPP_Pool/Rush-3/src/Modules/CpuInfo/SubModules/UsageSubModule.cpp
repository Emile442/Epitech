/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsageSubModule.cpp
*/

#include "UsageSubModule.hpp"

CpuInfo::UsageSubModule::UsageSubModule() : IMonitorSubModule("Usage")
{
    init();
}

void CpuInfo::UsageSubModule::refresh()
{
    std::vector<CPUData> entries1;
    std::vector<CPUData> entries2;

    _array.clear();

    ReadStatsCPU(entries1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ReadStatsCPU(entries2);

    putStats(entries1, entries2);
}

const std::vector<CPUUsage> &CpuInfo::UsageSubModule::getUsage() const
{
    return (_array);
}

size_t CpuInfo::UsageSubModule::GetIdleTime(const CPUData &e)
{
    return (e.times[S_IDLE] + e.times[S_IOWAIT]);
}

size_t CpuInfo::UsageSubModule::GetActiveTime(const CPUData &e)
{
    return (e.times[S_USER] + e.times[S_NICE] + e.times[S_SYSTEM] + e.times[S_IRQ] + e.times[S_SOFTIRQ] + e.times[S_STEAL] + e.times[S_GUEST] + e.times[S_GUEST_NICE]);
}

void CpuInfo::UsageSubModule::ReadStatsCPU(std::vector<CPUData> &entries)
{
    std::ifstream fileStat("/proc/stat");
    std::string line;
    const std::string str("cpu");

    while(std::getline(fileStat, line)) {
        if(!line.compare(0, str.size(), str)) {
            std::istringstream ss(line);
            entries.emplace_back(CPUData());
            CPUData & entry = entries.back();
            ss >> entry.cpu;
            if (entry.cpu.size() > str.size())
                entry.cpu.erase(0, str.size());
            for (int i = 0; i < NUM_CPU_STATES; ++i)
                ss >> entry.times[i];
        }
    }
}

void CpuInfo::UsageSubModule::putStats(const std::vector<CPUData> &entries1, const std::vector<CPUData> &entries2)
{
    const size_t NUM_ENTRIES = entries1.size();

    for(size_t i = 0; i < NUM_ENTRIES; ++i) {
        const CPUData & e1 = entries1[i];
        const CPUData & e2 = entries2[i];

        auto activeTime = static_cast<float>(GetActiveTime(e2) - GetActiveTime(e1));
        auto idleTime	= static_cast<float>(GetIdleTime(e2) - GetIdleTime(e1));

        if (e1.cpu != "cpu") {
            CPUUsage tmp;
            tmp.nbr = e1.cpu;
            tmp.active = (100.f * activeTime / (activeTime + idleTime));
            tmp.idle = (100.f * idleTime / (activeTime + idleTime));
            _array.push_back(tmp);
        }
    }
}
