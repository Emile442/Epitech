/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include "Borg.hpp"

namespace Borg {
    class BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();
            bool (Borg::Ship::*movePtr)(Destination);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
            void (Borg::Ship::*destroyPtr)(Federation::Ship*);
            bool move(Borg::Ship *ship, Destination dest);
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
            void destroy(Borg::Ship *ship, Federation::Ship *target);


        protected:
        private:
    };
}


#endif /* !BORGQUEEN_HPP_ */
