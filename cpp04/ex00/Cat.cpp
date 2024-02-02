#include "Cat.hpp"

#include <iostream>

Cat::Cat( void ) : Animal( "Cat" ) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( Cat const &source ) {
    std::cout << "Cat copy constructor called from " << source.getType()
              << std::endl;
    *this = source;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=( Cat const &source ) {
    std::cout << "Cat assignation operator called from " << source.getType()
              << " to " << getType() << std::endl;
    if ( this != &source ) {
        Animal::operator=( source );
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "I can bark!" << std::endl;
}
