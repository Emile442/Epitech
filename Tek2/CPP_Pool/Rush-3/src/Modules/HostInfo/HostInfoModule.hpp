/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OSInfoModule.hpp
*/

#ifndef HOSTINFOModule_H_
#define HOSTINFOModule_H_

#include "../../../app/Interface/IMonitorModule.hpp"

#include "SubModules/NameSubModule.hpp"
#include "SubModules/UsernameSubModule.hpp"

class HostInfoModule: public IMonitorModule {
    public:
        HostInfoModule();
        void refresh() override;
        const std::string & getName() const;
        const std::string & getUsername() const;

    private:
        HostInfo::NameSubModule _name;
        HostInfo::UsernameSubModule _username;

};

#endif //HOSTINFOModule_H_
