#include "Dog.hpp"

#include <iostream>

Dog::Dog( void ) : Animal( "Dog" ) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( Dog const &source ) {
    std::cout << "Dog copy constructor called from " << source.getType()
              << std::endl;
    *this = source;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=( Dog const &source ) {
    std::cout << "Dog assignation operator called from " << source.getType()
              << " to " << getType() << std::endl;
    if ( this != &source ) {
        Animal::operator=( source );
    }
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "No you can't..." << std::endl;
}
