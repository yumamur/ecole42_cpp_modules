#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main() {
    const AAnimal *animals[4];
    // const AAnimal  animal( "eheh" ); // error: cannot declare variable
    // ‘animal’ to be of abstract type ‘AbstractAnimal’

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
