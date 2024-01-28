#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie* horde = new Zombie[N];

    while ( N-- ) {
        horde[N] = Zombie( name );
    } 

    return horde;
}