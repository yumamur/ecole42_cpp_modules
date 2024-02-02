#include "Dog.hpp"

#include <cstdlib>
#include <iostream>

Dog::Dog( void ) : AAnimal( "Dog" ), _brain( new Brain() ) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( Dog const &source ) : AAnimal( source ), _brain( new Brain() ) {
    std::cout << "Dog copy constructor called from " << source.getType()
              << std::endl;
    for ( int i = 0; i < 100; i++ ) {
        _brain->setIdea( i, source._brain->getIdea( i ) );
    }
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog &Dog::operator=( Dog const &source ) {
    std::cout << "Dog assignation operator called from " << source.getType()
              << " to " << getType() << std::endl;
    if ( this != &source ) {
        AAnimal::operator=( source );
        for ( int i = 0; i < 100; i++ ) {
            _brain->setIdea( i, source._brain->getIdea( i ) );
        }
    }
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Barking " << _brain->getIdea( rand() % 100 ) << std::endl;
}
