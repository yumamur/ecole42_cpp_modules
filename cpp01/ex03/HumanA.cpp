#include "HumanA.h"
#include "Weapon.h"
#include <iostream>

HumanA::HumanA( std::string name, Weapon &wpn )
    : weapon(wpn)
{
    this->name = name;
}

HumanA::~HumanA() {}


void	HumanA::attack() {
	std::cout << this->name << " attacks with their "
        << this->weapon.getType() << std::endl;
}