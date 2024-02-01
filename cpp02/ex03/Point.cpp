#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x( 0 ), y( 0 ) {
}

Point::~Point() {
}

Point::Point( Point const &p ) : x( p.x ), y( p.y ) {
}

Point::Point( const float x, const float y ) : x( x ), y( y ) {
}

Point::Point( Fixed const x, Fixed const y ) : x( x ), y( y ) {
}

Point &Point::operator=( Point &p ) {
    ( Fixed ) x = p.getX();
    ( Fixed ) y = p.getY();
    return *this;
}

Fixed Point::getX( void ) const {
    return ( this->x );
}

Fixed Point::getY( void ) const {
    return ( this->y );
}

Point Point::operator-( Point &p ) const {
    return Point( this->getX() - p.getX(), this->getY() - p.getY() );
}

Point Point::operator+( Point &p ) const {
    return Point( this->getX() + p.getX(), this->getY() + p.getY() );
}

Point Point::operator*( Point &p ) const {
    return Point( this->getX() * p.getX(), this->getY() * p.getY() );
}

Point Point::operator/( Point &p ) const {
    return Point( this->getX() / p.getX(), this->getY() / p.getY() );
}

Fixed Point::dot( const Point &p1, const Point &p2 ) {
    return Fixed( p1.getX() * p2.getX() + p1.getY() * p2.getY() );
}

Fixed Point::magn( const Point &p1 ) {
    return Fixed::sqrt( p1.getX() * p1.getX() + p1.getY() * p1.getY() );
}

Fixed Point::magnR( const Point &p1 ) {
    return Fixed( p1.getX() * p1.getX() + p1.getY() * p1.getY() );
}

std::ostream &operator<<( std::ostream &o, Point const &p ) {
    o << "Point(" << p.getX() << ", " << p.getY() << ")";
    return o;
}
