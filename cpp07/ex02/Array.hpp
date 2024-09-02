#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {
  public:
    Array();
    Array( unsigned int n );
    Array( Array const &copy );
    ~Array();
    Array       &operator=( Array const &assign );
    T           &operator[]( long );
	const T     &operator[]( long ) const;
    unsigned int size() const;
    void         iter( void ( *f )( T const         &) ) const;
    T           &map( T ( *f )( T const           &) ) const;

  private:
    T            *_array;
    unsigned long _size;
};

#include "Array.tpp"

#endif       // !ARRAY_HPP
