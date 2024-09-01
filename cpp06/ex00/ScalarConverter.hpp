#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

#define TYPE_CHAR    0
#define TYPE_INT     1
#define TYPE_FLOAT   2
#define TYPE_DOUBLE  3
#define TYPE_PSEUDOS 4

class ScalarConverter {
  private:
    ScalarConverter();
    ScalarConverter( const ScalarConverter &copy );
    ScalarConverter &operator=( const ScalarConverter &assign );
    ~ScalarConverter();

  public:
    static void convert( const std::string input );
};

std::ostream &operator<<( std::ostream &out, const ScalarConverter &scalarConverter );

#endif
