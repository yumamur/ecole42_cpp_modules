#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap( "foo" );
    ClapTrap heheh( "heheh" );

    clapTrap.attack( "target" );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.attack( "target" );
    heheh.beRepaired( 15 );
}
