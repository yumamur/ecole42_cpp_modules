#include "Harl.h"

#include <iostream>

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
    void ( Harl::*f[4] )( void ) = { &Harl::debug, &Harl::info, &Harl::warning,
                                     &Harl::error };
    int         index;
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for ( index = 0; index < 4; index++ ) {
        if ( levels[index] == level ) {
            break;
        }
    }
    if ( index < 4 ) {
        ( this->*f[index] )();
    } else {
        std::cerr << "Invalid level: " << level << std::endl;
    }
}