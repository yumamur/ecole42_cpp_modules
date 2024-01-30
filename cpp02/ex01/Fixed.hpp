#ifndef FIXED_H
#define FIXED_H

#include <ostream>

#pragma once

class Fixed {
    public:
        Fixed();
        Fixed( int const );
        Fixed( float const );
        Fixed( const Fixed &fixed );
        ~Fixed();
        Fixed &operator=( const Fixed &fixed );
        float  toFloat( void ) const;
        int    toInt( void ) const;
        int    getRawBits( void ) const;
        void   setRawBits( int const );

    private:
        int              _fixed_point;
        static const int _fractional_bits = 8;
};
std::ostream &operator<<( std::ostream &os, const Fixed &fp );

#endif
