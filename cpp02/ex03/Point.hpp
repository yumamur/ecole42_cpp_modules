#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#pragma once

class Point {
    public:
        Point();
        ~Point();
        Point( Point const &p );
        Point( float const x, float const y );
        Point( Fixed const x, Fixed const y );

        Point       &operator=( Point &p );
        Point        operator+( Point &p ) const;
        Point        operator-( Point &p ) const;
        Point        operator*( Point &p ) const;
        Point        operator/( Point &p ) const;

        Fixed        getX( void ) const;
        Fixed        getY( void ) const;

        static Fixed dot( Point const &p1, Point const &p2 );
        static Fixed magn( Point const &p1 );
        static Fixed magnR( Point const &p1 );

    private:
        Fixed const x;
        Fixed const y;
};

std::ostream &operator<<( std::ostream &o, Point const &p );

#endif