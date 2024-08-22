#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), _guardGate( false ) {
    std::cout << "ScavTrap default constructor is called" << std::endl;
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor is called for " << _name << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ), _guardGate( false ) {
    std::cout << "ScavTrap name constructor is called for " << _name
              << std::endl;
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &source ) : ClapTrap( source ) {
    std::cout << "ScavTrap copy constructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &source ) {
    std::cout << "ScavTrap assignment operator is called from " << source._name
              << " to " << _name << std::endl;
    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
    return *this;
}

void ScavTrap::attack( std::string const &target ) {
    if ( _energyPoints == 0 && _hitPoints > 0 ) {
        std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
    } else if ( _hitPoints > 0 ) {
        _energyPoints -= 1;
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    _guardGate = !_guardGate;
    std::cout << "ScavTrap " << _name << " is now "
              << ( _guardGate ? "in" : "out of" ) << " gate keeper mode"
              << std::endl;
}
