#include "Zombie.hpp" 

Zombie* zombieHorde( int N, std::string name );

int main( void ) {
    Zombie* horde = zombieHorde( 5, "leyley" );

    delete [] horde;
}