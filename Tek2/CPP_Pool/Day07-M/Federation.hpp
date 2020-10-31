/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include <iostream>

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                void setAge(int age);
                int getAge();
            
            private:
                std::string _name;
                int _age;
        };

        class Ensign {
            public:
                explicit Ensign(std::string name);
                ~Ensign();
            private:
                std::string _name;
        };

        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                ~Ship();
                void setupCore(WarpSystem::Core* core);
                bool checkCore();
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes , Borg::Ship *target);

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core* _core;
                Federation::Starfleet::Captain* _captain;
                Destination _home;
                Destination _location;
                int _shield;
                int _photonTorpedo;

        };
    }

    class Ship {
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core* core);
            bool checkCore();
            WarpSystem::Core* getCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core* _core;
            Destination _home;
            Destination _location;

    };
} 

#endif /* !FEDERATION_HPP_ */
