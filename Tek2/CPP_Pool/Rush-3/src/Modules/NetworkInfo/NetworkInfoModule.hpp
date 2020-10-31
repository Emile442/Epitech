/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NetworkInfoModule.hpp
*/


#ifndef NETWORKINFOMODULE_H_
#define NETWORKINFOMODULE_H_

#include "../../../app/Interface/IMonitorModule.hpp"
#include "SubModules/UpSubModule.hpp"
#include "SubModules/DownSubModule.hpp"

class NetworkInfoModule: public IMonitorModule {
    public:
        NetworkInfoModule();
        void refresh() override;
        const std::string & getUp();
        const std::string & getDown();

    protected:
        NetworkInfo::UpSubModule _up;
        NetworkInfo::DownSubModule _down;
};


#endif //NETWORKINFOMODULE_H_
