#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap( "foo" );
    ClapTrap clapTrap( "bar" );
    ClapTrap heheh( "heheh" );

    clapTrap.attack( "target" );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.attack( "target" );
    heheh.beRepaired( 15 );
    scavTrap.attack( "target" );
    scavTrap.takeDamage( 5 );
    scavTrap.beRepaired( 5 );
    scavTrap.guardGate();
    scavTrap.guardGate();
    scavTrap.takeDamage( 150 );
}
