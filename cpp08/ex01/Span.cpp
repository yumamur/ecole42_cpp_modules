#include "Span.hpp"

#include <algorithm>
#include <exception>
#include <functional>

Span::Span( unsigned int cap ) : _cap( cap ), _size( 0 ) {
  _arr.reserve( cap );       // Reserve capacity for _cap elements
}

Span::Span( Span const &other ) {
  *this = other;
}

Span &Span::operator=( Span const &other ) {
  if ( this != &other ) {
    _cap  = other._cap;
    _size = other._size;
    _arr  = other._arr;       // Correctly copy the vector
  }
  return *this;
}

Span::~Span() {
}

void Span::addNumber( int n ) {
  if ( _size >= _cap ) {
    throw std::exception();
  }
  _arr.insert( std::upper_bound( _arr.begin(), _arr.end(), n ), n );       // Insert sorted
  _size = _arr.size();                                                     // Update _size
}

void Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
  std::vector<int> v( begin, end );
  std::sort( v.begin(), v.end() );       // Sort the incoming numbers

  if ( _size + v.size() > _cap ) {       // Ensure we do not exceed capacity
    throw std::exception();
  }

  std::vector<int> temp( _arr.size() + v.size() );
  std::merge( _arr.begin(), _arr.end(), v.begin(), v.end(), temp.begin() );

  _arr.swap( temp );
  _size = _arr.size();       // Update _size
}

unsigned int Span::shortestSpan() {
  if ( _size < 2 ) {
    throw std::exception();
  }
  std::vector<int> diff( _arr.size() - 1 );
  std::transform( _arr.begin() + 1, _arr.end(), _arr.begin(), diff.begin(), std::minus<int>() );
  return *std::min_element( diff.begin(), diff.end() );
}

unsigned int Span::longestSpan() {
  if ( _size < 2 )
    throw std::exception();
  return _arr[_size - 1] - _arr[0];
}

void Span::forEach( void ( *f )( int ) ) {
  for ( unsigned int i = 0; i < _size; i++ )
    f( _arr[i] );
}
