#include "ICharacter.hpp"
#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria( "ice" ) {
}

Ice::Ice( Ice const &other ) : AMateria( other ) {
}

Ice &Ice::operator=( Ice const &other ) {
  if ( this != &other ) {
    AMateria::operator=( other );
  }
  return *this;
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
  return new Ice( *this );
}

void Ice::use( ICharacter &target ) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
