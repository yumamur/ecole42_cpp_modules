#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#pragma once

class Weapon {
	public:
		Weapon( std::string );
		~Weapon();
		std::string	getType() const;
		void		setType( std::string );

	private:
		Weapon();
		std::string type;
};

#endif