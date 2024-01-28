#ifndef HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.h"
#include <string>
#pragma once

class HumanA {
	public:
		HumanA( std::string, Weapon & );
		~HumanA();
		void	attack( void );

	private:
		HumanA();
		std::string	name;
		Weapon 		&weapon;
};

#endif