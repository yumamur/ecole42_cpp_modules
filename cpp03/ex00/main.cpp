#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap( "leyley" );

    clapTrap.attack( "target" );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.attack( "target" );

    return 0;
}
