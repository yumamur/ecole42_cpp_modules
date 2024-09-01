#include "Test.hpp"
#include <cstdlib>
#include <sstream>

Test::Test() {
	std::stringstream ss;
	ss << "default" << rand();
	name = ss.str();
}

Test::Test( Test const &copy ) : name( copy.name ) {
  *this = copy;
}

Test::~Test() {
}

Test &Test::operator=( Test const &assign ) {
  if ( this != &assign ) {
    *this = assign;
  }
  return *this;
}

std::ostream &operator<<( std::ostream &o, Test const &i ) {
  o << i.name;
  return o;
}
