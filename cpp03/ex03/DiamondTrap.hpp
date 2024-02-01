#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap( void );
        DiamondTrap( std::string const &name );
        DiamondTrap( DiamondTrap const &source );
        ~DiamondTrap( void );

        DiamondTrap &operator=( DiamondTrap const &source );

        void         whoAmI( void ) const;

    private:
        std::string _name;
};

#endif
