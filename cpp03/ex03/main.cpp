#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    DiamondTrap diamondTrap( "foo" );

    diamondTrap.attack( "target" );
    diamondTrap.takeDamage( 5 );
    diamondTrap.beRepaired( 5 );
    diamondTrap.highFivesGuys();
    diamondTrap.guardGate();
    diamondTrap.whoAmI();

	std::cout << std::endl;
	DiamondTrap iamondTrap;
	std::cout << std::endl;
}
