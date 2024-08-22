#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap( name ) {
    std::cout << "FragTrap name constructor called for " << _name << std::endl;
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const &source ) : ClapTrap( source ) {
    std::cout << "FragTrap copy constructor called from " << std::endl;

    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
}

FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const &source ) {
    std::cout << "FragTrap assignation operator called from " << source._name
              << " to " << _name << std::endl;
    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys( void ) {
    std::cout << "FragTrap " << _name << " wants to high you five!"
              << std::endl;
}
