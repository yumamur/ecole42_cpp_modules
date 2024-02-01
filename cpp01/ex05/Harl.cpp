#include "Harl.h"

#include <iostream>
#include <map>

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug( void ) {
    std::cout << "debug" << std::endl;
}

void Harl::info( void ) {
    std::cout << "info" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "warning" << std::endl;
}

void Harl::error( void ) {
    std::cout << "error" << std::endl;
}

void Harl::complain( std::string level ) {
    std::map<std::string, void ( Harl::* )( void )> level_map;
    level_map["DEBUG"]   = &Harl::debug;
    level_map["INFO"]    = &Harl::info;
    level_map["WARNING"] = &Harl::warning;
    level_map["ERROR"]   = &Harl::error;

    if ( level_map.find( level ) != level_map.end() ) {
        ( this->*level_map[level] )();
    }
}