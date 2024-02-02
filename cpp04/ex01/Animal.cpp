#include "Animal.hpp"

#include <iostream>

Animal::Animal( void ) : _type( "Animal" ) {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string const &type ) : _type( type ) {
    std::cout << "Animal type constructor called for " << _type << std::endl;
}

Animal::Animal( Animal const &source ) {
    std::cout << "Animal copy constructor called from " << source._type
              << std::endl;
    *this = source;
}

Animal::~Animal( void ) {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=( Animal const &source ) {
    std::cout << "Animal assignation operator called from " << source._type
              << " to " << _type << std::endl;
    if ( this != &source ) {
        _type = source._type;
    }
    return *this;
}

std::string const &Animal::getType( void ) const {
    return _type;
}

void Animal::makeSound( void ) const {
    std::cout << "Animal sound" << std::endl;
}
