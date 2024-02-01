#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name         = "default";
    _hitPoints    = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( std::string const &name ) :
    ClapTrap( name + "_clap_name" ), ScavTrap( name ), FragTrap( name ),
    _name( name ) {
    _name         = name;
    _hitPoints    = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap name constructor called for " << _name
              << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &source ) :
    ClapTrap( source ), ScavTrap( source ), FragTrap( source ) {
    std::cout << "DiamondTrap copy constructor called from " << std::endl;

    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &source ) {
    std::cout << "DiamondTrap assignation operator called from " << source._name
              << " to " << _name << std::endl;
    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
    return *this;
}

void DiamondTrap::whoAmI( void ) const {
    std::cout << "DiamondTrap name is " << _name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}
