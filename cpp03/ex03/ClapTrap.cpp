#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() {
    _name = "Horse with no name";
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :
    _name( name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {
    std::cout << "ClapTrap name constructor called with " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &source ) :
    _name( source._name ), _hitPoints( source._hitPoints ),
    _energyPoints( source._energyPoints ),
    _attackDamage( source._attackDamage ) {
    std::cout << "ClapTrap copy constructor called from " << source._name
              << " to " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &source ) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if ( this != &source ) {
        _name         = source._name;
        _hitPoints    = source._hitPoints;
        _energyPoints = source._energyPoints;
        _attackDamage = source._attackDamage;
    }
    return *this;
}

void ClapTrap::attack( std::string const &target ) {
    if ( _energyPoints == 0 && _hitPoints > 0 ) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    } else if ( _hitPoints > 0 ) {
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    }
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ( amount < _hitPoints ) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage!" << std::endl;
    } else if ( _hitPoints > 0 ) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage and dies!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if ( _energyPoints > 0 && _hitPoints > 0 ) {
        _energyPoints -= 1;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount
                  << " points of health!" << std::endl;
    } else if ( _hitPoints > 0 ) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    }
}
