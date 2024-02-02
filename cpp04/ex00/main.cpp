#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main( void ) {
    const Animal *animals[4];

    for ( int i = 0; i < 4; i++ ) {
        if ( i % 2 == 0 ) {
            std::cout << "Creating a cat at index " << i << std::endl;
            animals[i] = new Cat();
        } else {
            std::cout << "Creating a dog at index " << i << std::endl;
            animals[i] = new Dog();
        }
    }

    for ( int i = 0; i < 4; i++ ) {
        std::cout << "Animal " << i << " with the type "
                  << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    return 0;
}
