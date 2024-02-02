#include "Brain.hpp"

#include <iostream>
#include <sstream>

Brain::Brain( void ) {
    std::ostringstream oss;

    for ( int i = 0; i < 100; i++ ) {
        oss << i;
        _ideas[i] = "Idea #" + oss.str();
        oss.str( "" );
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( Brain const &source ) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = source;
}

Brain::~Brain( void ) {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=( Brain const &source ) {
    std::cout << "Brain assignation operator called" << std::endl;
    if ( this != &source ) {
        for ( int i = 0; i < 100; i++ ) {
            _ideas[i] = source._ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea( int index ) const {
    return _ideas[index];
}

void Brain::setIdea( int index, std::string idea ) {
    _ideas[index] = idea;
}
