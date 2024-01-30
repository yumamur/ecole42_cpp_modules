#include "Fixed.hpp"

#include <iostream>
#include <ostream>

Fixed::Fixed() : _fixed_point( 0 ) {
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