#include "Harl.h"

#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> map;

Harl::Harl() {
	map["DEBUG"]   = 0;
	map["INFO"]	   = 1;
	map["WARNING"] = 2;
	map["ERROR"]   = 3;
}

Harl::~Harl() {
}

void Harl::debug( void ) {
	std::cout << "Debug" << std::endl;
}

void Harl::info( void ) {
	std::cout << "Info" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "Warning" << std::endl;
}

void Harl::error( void ) {
	std::cout << "Error" << std::endl;
}

void Harl::complain( std::string level ) {
	int index;

	if ( map.find( level ) != map.end() ) {
		index = map[level];
	} else {
		index = -1;
	}
	switch ( index ) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cerr << "Invalid level: " << level << std::endl;
	}
}
