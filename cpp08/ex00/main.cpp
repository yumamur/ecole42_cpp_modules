#include "easyfind.hpp"

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for ( int i = 0; i < 10; i++ )
    v.push_back( i );
  std::vector<int>::iterator it;

  it = easyfind( v, 11 );
  if ( it == v.end() )
    std::cout << "Not found" << std::endl;
  else
    std::cout << "Found: " << *it << std::endl;

  it = easyfind( v, 5 );
  if ( it == v.end() )
    std::cout << "Not found" << std::endl;
  else
    std::cout << "Found: " << *it << std::endl;
  return 0;
}
