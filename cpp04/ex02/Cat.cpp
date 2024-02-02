#include "Cat.hpp"

#include <cstdlib>
#include <iostream>

Cat::Cat( void ) : AAnimal( "Cat" ), _brain( new Brain() ) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( Cat const &source ) : AAnimal( source ), _brain( new Brain() ) {
    for ( int i = 0; i < 100; i++ ) {
        _brain->setIdea( i, source._brain->getIdea( i ) );
    }
    std::cout << "Cat copy constructor called from " << source.getType()
              << std::endl;
}

Cat::~Cat( void ) {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=( Cat const &source ) {
    std::cout << "Cat assignation operator called from " << source.getType()
              << " to " << getType() << std::endl;
    if ( this != &source ) {
        AAnimal::operator=( source );
        for ( int i = 0; i < 100; i++ ) {
            _brain->setIdea( i, source._brain->getIdea( i ) );
        }
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Still tries to bark " << _brain->getIdea( rand() % 100 )
              << std::endl;
}
