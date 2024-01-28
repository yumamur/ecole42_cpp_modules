#include "Zombie.hpp" 

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main( void ) {
    Zombie* carl = newZombie("heleloy");

    carl->announce();

    randomChump("chump");
    delete carl;
}