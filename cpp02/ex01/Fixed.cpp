#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : _fixed_point( 0 ) {
    std::cout << "constructor" << std::endl;
}

Fixed::Fixed( int const value ) : _fixed_point( value << _fractional_bits ) {
    std::cout << "constructor" << std::endl;
}

Fixed::Fixed( float const value ) :
    _fixed_point( int( value * ( 1 << _fractional_bits ) ) ) {
    std::cout << "constructor" << std::endl;
}

Fixed::Fixed( const Fixed &to_copy ) : _fixed_point( to_copy._fixed_point ) {
    std::cout << "copy constructor" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &other ) {
    std::cout << "= operator" << std::endl;
    _fixed_point = other._fixed_point;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "destructor" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "get raw bits" << std::endl;
    return _fixed_point;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "set raw bits" << std::endl;
    _fixed_point = raw;
}

float Fixed::toFloat() const {
    return float( _fixed_point ) / float( 1 << _fractional_bits );
}

int Fixed::toInt() const {
    return roundf( _fixed_point >> _fractional_bits );
}

std::ostream &operator<<( std::ostream &os, const Fixed &fp ) {
    os << fp.toFloat();
    return os;
}
