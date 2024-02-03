#include "HumanB.h"
#include "Weapon.h"
#include <iostream>
#include <string>

HumanB::HumanB( std::string name ) {
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon( Weapon &weaponPtr )
{
	this->weapon = &weaponPtr;
}

void	HumanB::attack() {
	if (weapon != NULL) {
		std::cout << this->name << " attacks with their "
			<< this->weapon->getType() << std::endl;
	} else {
		std::cout << "You haven't given " << name << " a weapon!" << std::endl;
	}
}