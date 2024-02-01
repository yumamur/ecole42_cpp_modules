#include "Harl.h"

#include <iostream>
#include <string>

Harl::Harl() {
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
    int         index;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for ( index = 0; index < 4; index++ ) {
        if ( levels[index] == level ) {
            break;
        }
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
