#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class Test {
  public:
    Test();
    Test( Test const &copy );
    ~Test();
    Test &operator=( Test const &assign );
	
	std::string name;
};

std::ostream &operator<<( std::ostream &o, Test const &i );

#endif       // !TEST_HPP
