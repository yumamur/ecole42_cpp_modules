#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main() {
    const Animal *animals[4];

    for ( int i = 0; i < 2; i++ ) {
        std::cout << "Creating a cat" << std::endl;
        animals[i] = new Cat();
    }
    for ( int i = 2; i < 4; i++ ) {
        std::cout << "Creating a dog" << std::endl;
        animals[i] = new Dog();
    }

    for ( int i = 0; i < 4; i++ ) {
        std::cout << "Animal " << i << " says: ";
        animals[i]->makeSound();
    }

    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }
    return 0;
}
