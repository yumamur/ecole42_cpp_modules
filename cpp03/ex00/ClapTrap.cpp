#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :
    name( name ), hitPoints( 10 ), energyPoints( 10 ), attackDamage( 0 ) {
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &source ) :
    name( source.name ), hitPoints( source.hitPoints ),
    energyPoints( source.energyPoints ), attackDamage( source.attackDamage ) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &source ) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if ( this != &source ) {
        name         = source.name;
        hitPoints    = source.hitPoints;
        energyPoints = source.energyPoints;
        attackDamage = source.attackDamage;
    }
    return *this;
}

void ClapTrap::attack( std::string const &target ) {
    if ( energyPoints == 0 && hitPoints > 0 ) {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
    } else if ( hitPoints > 0 ) {
        energyPoints -= 1;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
    }
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ( amount < hitPoints ) {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage!" << std::endl;
    } else if ( hitPoints > 0 ) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage and dies!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
    }
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if ( energyPoints > 0 && hitPoints > 0 ) {
        energyPoints -= 1;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired for " << amount
                  << " points of health!" << std::endl;
    } else if ( hitPoints > 0 ) {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
    }
}
