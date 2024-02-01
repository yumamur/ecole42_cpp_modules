#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamondTrap( "foo" );

    diamondTrap.attack( "target" );
    diamondTrap.takeDamage( 5 );
    diamondTrap.beRepaired( 5 );
    diamondTrap.highFivesGuys();
    diamondTrap.guardGate();
    diamondTrap.whoAmI();
}
