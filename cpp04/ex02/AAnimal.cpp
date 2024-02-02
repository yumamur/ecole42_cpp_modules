#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal( void ) : _type( "AAnimal" ) {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string const &type ) : _type( type ) {
    std::cout << "AAnimal type constructor called for " << _type << std::endl;
}

AAnimal::AAnimal( AAnimal const &source ) {
    std::cout << "AAnimal copy constructor called from " << source._type
              << std::endl;
    *this = source;
}

AAnimal::~AAnimal( void ) {
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=( AAnimal const &source ) {
    std::cout << "AAnimal assignation operator called from " << source._type
              << " to " << _type << std::endl;
    if ( this != &source ) {
        _type = source._type;
    }
    return *this;
}

std::string const &AAnimal::getType( void ) const {
    return _type;
}

void AAnimal::makeSound( void ) const {
    std::cout << "AAnimal sound" << std::endl;
}
