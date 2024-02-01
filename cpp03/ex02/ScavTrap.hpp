#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private:
        bool _guardGate;

    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( ScavTrap const &other );
        ScavTrap &operator=( ScavTrap const &other );

        void      attack( std::string const &target );
        void      guardGate();
};

#endif
