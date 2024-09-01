#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

Base *generate() {
  int i = rand() % 3;
  if ( i == 0 ) {
    std::cout << "A generated" << std::endl;
    return new A();
  } else if ( i == 1 ) {
    std::cout << "B generated" << std::endl;
    return new B();
  } else {
    std::cout << "C generated" << std::endl;
    return new C();
  }
}

void identify( Base *p ) {
  std::cout << "Identify by pointer: ";
  if ( dynamic_cast<A *>( p ) ) {
    std::cout << "A" << std::endl;
  } else if ( dynamic_cast<B *>( p ) ) {
    std::cout << "B" << std::endl;
  } else if ( dynamic_cast<C *>( p ) ) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Unknown" << std::endl;
  }
}

void identify( Base &p ) {
  std::cout << "Identify by reference: ";
  try {
    ( void ) dynamic_cast<A &>( p );
    std::cout << "A" << std::endl;
  } catch ( std::exception &e ) {
  }
  try {
    ( void ) dynamic_cast<B &>( p );
    std::cout << "B" << std::endl;
  } catch ( std::exception &e ) {
  }
  try {
    ( void ) dynamic_cast<C &>( p );
    std::cout << "C" << std::endl;
  } catch ( std::exception &e ) {
  }
}

int main() {
  srand( time( 0 ) );
  for ( int i = 0; i < 10; i++ ) {
    Base *p = generate();
    identify( p );
    identify( *p );
  }
}
