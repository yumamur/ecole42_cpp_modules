#include "Fixed.hpp"

#include <iostream>
#include <ostream>

Fixed::Fixed() : _fixed_point( 0 ) {
}

Fixed::~Fixed() {
}

Fixed::Fixed( int const value ) : _fixed_point( value ) {
}

Fixed::Fixed( float const value ) :
    _fixed_point( int( value * ( 1 << _fractional_bits ) ) ) {
}

Fixed::Fixed( const Fixed &to_copy ) : _fixed_point( to_copy._fixed_point ) {
}

Fixed &Fixed::operator=( const Fixed &other ) {
    _fixed_point = other._fixed_point;
    return *this;
}

int Fixed::getRawBits( void ) const {
    return _fixed_point;
}

void Fixed::setRawBits( int const raw ) {
    _fixed_point = raw;
}

float Fixed::toFloat() const {
    return float( _fixed_point ) / float( 1 << _fractional_bits );
}

int Fixed::toInt() const {
    return _fixed_point >> _fractional_bits;
}

std::ostream &operator<<( std::ostream &os, const Fixed &fp ) {
    os << fp.toFloat();
    return os;
}

bool Fixed::operator>( const Fixed &other ) const {
    return _fixed_point > other._fixed_point;
}

bool Fixed::operator<( const Fixed &other ) const {
    return _fixed_point < other._fixed_point;
}

bool Fixed::operator>=( const Fixed &other ) const {
    return _fixed_point >= other._fixed_point;
}

bool Fixed::operator<=( const Fixed &other ) const {
    return _fixed_point <= other._fixed_point;
}

bool Fixed::operator==( const Fixed &other ) const {
    return _fixed_point == other._fixed_point;
}

bool Fixed::operator!=( const Fixed &other ) const {
    return _fixed_point != other._fixed_point;
}

Fixed Fixed::operator+( const Fixed &other ) const {
    return _fixed_point + other._fixed_point;
}

Fixed Fixed::operator-( const Fixed &other ) const {
    return _fixed_point - other._fixed_point;
}

Fixed Fixed::operator*( const Fixed &other ) const {
    return Fixed( _fixed_point * other._fixed_point );       // No need to shift
}

Fixed Fixed::operator/( const Fixed &other ) const {
    return Fixed( ( _fixed_point << _fractional_bits ) / other._fixed_point );
}

Fixed Fixed::operator++() {
    ++_fixed_point;
    return *this;
}

Fixed Fixed::operator--() {
    --_fixed_point;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed t = *this;
    ++this->_fixed_point;
    return t;
}

Fixed Fixed::operator--( int ) {
    Fixed t = *this;
    --this->_fixed_point;
    return t;
}

Fixed &Fixed::max( Fixed &fp1, Fixed &fp2 ) {
    return fp1 > fp2 ? fp1 : fp2;
}

const Fixed &Fixed::max( const Fixed &fp1, const Fixed &fp2 ) {
    return fp1 > fp2 ? fp1 : fp2;
}

Fixed &Fixed::min( Fixed &fp1, Fixed &fp2 ) {
    return fp1 < fp2 ? fp1 : fp2;
}

Fixed const &Fixed::min( const Fixed &fp1, const Fixed &fp2 ) {
    return fp1 < fp2 ? fp1 : fp2;
}