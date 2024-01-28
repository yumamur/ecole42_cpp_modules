#include "Weapon.h"
#include <string>

Weapon::Weapon( std:: string type) {
    this->type = type;
}

Weapon::~Weapon() {}

void    Weapon::setType( std::string type ) {
    this->type = type;
}

std::string Weapon::getType( void ) const {
    return (this->type);
}
