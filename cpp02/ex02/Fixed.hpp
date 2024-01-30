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

        Fixed              &operator=( const Fixed &fixed );
        bool                operator>( const Fixed &fixed ) const;
        bool                operator<( const Fixed &fixed ) const;
        bool                operator>=( const Fixed &fixed ) const;
        bool                operator<=( const Fixed &fixed ) const;
        bool                operator==( const Fixed &fixed ) const;
        bool                operator!=( const Fixed &fixed ) const;

        Fixed               operator+( const Fixed &fixed ) const;
        Fixed               operator-( const Fixed &fixed ) const;
        Fixed               operator*( const Fixed &fixed ) const;
        Fixed               operator/( const Fixed &fixed ) const;

        Fixed               operator++();
        Fixed               operator++( int );
        Fixed               operator--();
        Fixed               operator--( int );

        float               toFloat( void ) const;
        int                 toInt( void ) const;
        int                 getRawBits( void ) const;
        void                setRawBits( int const );

        static Fixed       &min( Fixed &, Fixed       &);
        static Fixed const &min( Fixed const &, Fixed const & );
        static Fixed       &max( Fixed &, Fixed       &);
        static Fixed const &max( Fixed const &, Fixed const & );

    private:
        int              _fixed_point;
        static const int _fractional_bits = 8;
};

std::ostream &operator<<( std::ostream &os, const Fixed &fp );

#endif
