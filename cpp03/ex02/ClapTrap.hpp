#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
    protected:
        std::string  _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &source );
        ClapTrap( std::string name,
                  int         hitPoints,
                  int         energyPoints,
                  int         attackDamage );
        ~ClapTrap();

        ClapTrap &operator=( const ClapTrap &source );

        void      attack( std::string const &target );
        void      takeDamage( unsigned int amount );
        void      beRepaired( unsigned int amount );
};

#endif
