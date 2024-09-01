#include "Array.hpp"

#include <exception>
#include <iostream>
#include <limits>

template<typename T>
Array<T>::Array() : _array( NULL ), _size( 0 ) {
}

template<typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n] ), _size( n ) {
}

template<typename T>
Array<T>::Array( Array const &copy ) : _array( new T[copy._size] ), _size( copy._size ) {
  for ( unsigned int i = 0; i < _size; i++ ) {
    _array[i] = copy._array[i];
  }
}

template<typename T>
Array<T>::~Array() {
  delete[] _array;
}

template<typename T>
Array<T> &Array<T>::operator=( Array const &assign ) {
  if ( this != &assign ) {
    delete[] _array;
    _array = new T[assign._size];
    _size  = assign._size;
    for ( unsigned int i = 0; i < _size; i++ ) {
      _array[i] = assign._array[i];
    }
  }
  return *this;
}

template<typename T>
T &Array<T>::operator[]( long i ) {
  std::cout << i << std::endl;
  if ( i < 0 || i > std::numeric_limits<int>::max() || ( unsigned long ) i >= _size ) {
    throw std::exception();
  }
  return _array[i];
}

template<typename T>
unsigned int Array<T>::size() const {
  return _size;
}

template<typename T>
void Array<T>::iter( void ( *f )( T const & ) ) const {
  for ( unsigned int i = 0; i < _size; i++ ) {
    f( _array[i] );
  }
}

template<typename T>
T &Array<T>::map( T ( *f )( T const & ) ) const {
  Array<T> result( _size );
  for ( unsigned int i = 0; i < _size; i++ ) {
    result[i] = f( _array[i] );
  }
  return result;
}

template<typename T>
std::ostream &operator<<( std::ostream &os, Array<T> const &array ) {
  os << "[";
  for ( unsigned int i = 0; i < array.size(); i++ ) {
    os << array[i];
    if ( i < array.size() - 1 ) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}
