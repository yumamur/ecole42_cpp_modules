#include "Character.hpp"

Character::Character( std::string const &name ) : _name( name ) {
  for ( int i = 0; i < 4; i++ ) {
    _inventory[i] = NULL;
  }
}

Character::Character( Character const &other ) : _name( other._name ) {
  for ( int i = 0; i < 4; i++ ) {
    _inventory[i] = other._inventory[i];
  }
}

Character &Character::operator=( Character const &other ) {
  if ( this != &other ) {
    _name = other._name;
    for ( int i = 0; i < 4; i++ ) {
      _inventory[i] = other._inventory[i];
    }
  }
  return *this;
}

Character::~Character() {
  for ( int i = 0; i < 4; i++ ) {
    if ( _inventory[i] != NULL ) {
      delete _inventory[i];
    }
  }
}

std::string const &Character::getName() const {
  return _name;
}

void Character::equip( AMateria *m ) {
  for ( int i = 0; i < 4; i++ ) {
    if ( _inventory[i] == NULL ) {
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip( int idx ) {
  if ( idx >= 0 && idx < 4 ) {
    _inventory[idx] = NULL;
  }
}

void Character::use( int idx, ICharacter &target ) {
  if ( idx && _inventory[idx] != NULL ) {
    _inventory[idx]->use( target );
  }
}
