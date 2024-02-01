#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    FragTrap fragTrap( "foo" );
    ScavTrap scavTrap( "bar" );
    ClapTrap clapTrap( "baz" );

    clapTrap.attack( "target" );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.takeDamage( 5 );
    clapTrap.attack( "target" );
    scavTrap.attack( "target" );
    scavTrap.takeDamage( 5 );
    scavTrap.beRepaired( 5 );
    scavTrap.guardGate();
    scavTrap.guardGate();
    scavTrap.takeDamage( 150 );
    fragTrap.attack( "target" );
    fragTrap.takeDamage( 5 );
    fragTrap.beRepaired( 5 );
    fragTrap.highFivesGuys();
    fragTrap.takeDamage( 150 );
}
