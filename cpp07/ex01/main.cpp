#include "iter.hpp"
#include "Test.hpp"

#include <iostream>

template<typename T>
void print( T const &x ) {
  std::cout << x << std::endl;
}

int main() {
  int a[] = { 1, 2, 3, 4, 5 };
  iter( a, 5, print );

  std::string b[] = { "one", "two", "three", "four", "five" };
  iter( b, 5, print );

  Test c[] = { Test(), Test(), Test(), Test(), Test() };
  iter( c, 5, print );

  return 0;
}
