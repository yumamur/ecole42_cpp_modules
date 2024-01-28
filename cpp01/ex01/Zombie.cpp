#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie( void ) {}

Zombie::Zombie( std::string name ) {
    this->name = name;
}

Zombie::~Zombie( void ) {
    std::cout << this->name << " won't want any more brainz..." << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}