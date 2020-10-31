/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OSInfoModule.hpp
*/

#ifndef OSINFOModule_H_
#define OSINFOModule_H_

#include "../../../app/Interface/IMonitorModule.hpp"

#include "SubModules/NameSubModule.hpp"
#include "SubModules/VersionSubModule.hpp"
#include "SubModules/OsVersionSubModule.hpp"

class OSInfoModule: public IMonitorModule {
    public:
        OSInfoModule();
        void refresh() override;
        const std::string & getName() const;
        const std::string & getVersion() const;
        const std::string & getOsVersion() const;

    private:
        OSInfo::NameSubModule _name;
        OSInfo::VersionSubModule _version;
        OSInfo::OsVersionSubModule _osVersion;


};

#endif //OSINFOModule_H_
