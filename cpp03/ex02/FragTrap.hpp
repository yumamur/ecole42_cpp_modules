#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap( void );
        FragTrap( std::string const &name );
        FragTrap( FragTrap const &src );
        ~FragTrap( void );

        FragTrap &operator=( FragTrap const &rhs );

        void      highFivesGuys( void );

    private:
};

#endif
