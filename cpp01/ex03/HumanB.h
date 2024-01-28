#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>
#pragma once

class HumanB {
	public:
		HumanB( std::string );
		~HumanB();
		void		attack( void );
		void 		setWeapon( Weapon & );

	private:
		HumanB();
		std::string	name;
		Weapon 		*weapon;
};

#endif