#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <ostream>
#include <stdlib.h>
#include <string>

int    type;
char   theChar;
int    theInt;
float  theFloat;
double theDouble;

std::string pseudoFloat[3]  = { "-inff", "+inff", "nanf" };
std::string pseudoDouble[3] = { "-inf", "+inf", "nan" };

int    checkDigit( double temp, std::string toConvert ) {
  if ( temp / 10 == 0 && toConvert.find( '.' ) == std::string::npos )
    return ( 1 );
  return ( 0 );
}

void fromChar() {
  theInt    = static_cast<int>( theChar );
  theFloat  = static_cast<float>( theChar );
  theDouble = static_cast<double>( theChar );

  std::cout << "Char: '" << theChar << "'" << std::endl;
  std::cout << "Int: " << theInt << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision( 1 ) << theFloat << "f" << std::endl;
  std::cout << "Double: " << theDouble << std::endl;

  return;
}

void fromInt() {
  if ( theInt <= 126 && theInt >= 32 ) {
    theChar = static_cast<char>( theInt );
    std::cout << "Char: '" << theChar << "'" << std::endl;
  } else if ( ( theInt >= 0 && theInt <= 31 ) || theInt == 127 )
    std::cout << "Char: Non displayable" << std::endl;
  else
    std::cout << "Char: impossible" << std::endl;

  theFloat  = static_cast<float>( theInt );
  theDouble = static_cast<double>( theInt );

  std::cout << "Int: " << theInt << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision( 1 ) << theFloat << "f" << std::endl;
  std::cout << "Double: " << theDouble << std::endl;

  return;
}

void fromFloat() {
  if ( theFloat <= 126 && theFloat >= 32 ) {
    theChar = static_cast<char>( theFloat );
    std::cout << "Char: '" << theChar << "'" << std::endl;
  } else if ( ( theFloat >= 0 && theFloat <= 31 ) || theFloat == 127 )
    std::cout << "Char: Non displayable" << std::endl;
  else
    std::cout << "Char: impossible" << std::endl;
  if ( theFloat > 2147483647.0 || theFloat < -2147483648.0 )
    std::cout << "Int: impossible" << std::endl;
  else {
    theInt = static_cast<int>( theFloat );
    std::cout << "Int: " << theInt << std::endl;
  }
  theDouble = static_cast<double>( theFloat );
  std::cout << "Float: " << std::fixed << std::setprecision( 1 ) << theFloat << "f" << std::endl;
  std::cout << "Double: " << theDouble << std::endl;

  return;
}

void fromDouble() {
  if ( theDouble <= 126 && theDouble >= 32 ) {
    theChar = static_cast<char>( theDouble );
    std::cout << "Char: '" << theChar << "'" << std::endl;
  } else if ( ( theDouble >= 0 && theDouble <= 31 ) || theDouble == 127 )
    std::cout << "Char: Non displayable" << std::endl;
  else
    std::cout << "Char: impossible" << std::endl;
  if ( theDouble > 2147483647.0 || theDouble < -2147483648.0 )
    std::cout << "Int: impossible" << std::endl;
  else {
    theInt = static_cast<int>( theDouble );
    std::cout << "Int: " << theInt << std::endl;
  }
  if ( abs( theDouble ) > FLT_MAX )
    std::cout << "Float: "
              << "inf" << std::endl;
  else {
    theFloat = static_cast<float>( theDouble );
    std::cout << "Float: " << std::fixed << std::setprecision( 1 ) << theFloat << "f" << std::endl;
  }
  std::cout << "Double: " << theDouble << std::endl;
  return;
}

int checkInt( double temp, std::string toConvert ) {
  if ( toConvert.find( '.' ) != std::string::npos )
    return ( -1 );
  if ( temp > INT_MAX || temp < INT_MIN )
    return ( -1 );
  type   = TYPE_INT;
  theInt = static_cast<int>( temp );
  return ( type );
}

int checkFloat( double temp, std::string toConvert ) {
  if ( ( toConvert.find( '.' ) == std::string::npos ) &&
       ( toConvert.find( 'f' ) == std::string::npos ) )
    return ( -1 );

  int i = 0, j = 0;

  while ( toConvert[i] != 0 ) {
    if ( toConvert[i] == 'f' )
      j++;
    i++;
  }
  if ( j > 1 || toConvert[i - 1] != 'f' )
    return ( -1 );
  if ( abs( temp ) > FLT_MAX )
    return ( -1 );
  type     = TYPE_FLOAT;
  theFloat = static_cast<float>( temp );
  return ( type );
}

int checkDouble( double temp, std::string toConvert ) {
  if ( toConvert.find( 'f' ) != std::string::npos )
    return ( 1 );
  type      = TYPE_DOUBLE;
  theDouble = static_cast<double>( temp );
  return ( type );
}

int single( std::string toConvert ) {
  if ( isdigit( *toConvert.c_str() ) ) {
    type   = TYPE_INT;
    theInt = atoi( toConvert.c_str() );
    return ( TYPE_INT );
  } else if ( isprint( *toConvert.c_str() ) ) {
    type    = TYPE_CHAR;
    theChar = toConvert[0];
    return ( TYPE_CHAR );
  }
  return ( -1 );
}

int pseudoLiterals( std::string toConvert ) {
  int         i;

  for ( i = 0; i < 3; i++ ) {
    if ( toConvert.compare( pseudoFloat[i] ) == 0 )
      break;
    if ( toConvert.compare( pseudoDouble[i] ) == 0 )
      break;
  }
  if ( i < 3 ) {
    theFloat  = strtof( pseudoFloat[i].c_str(), NULL );
    theDouble = strtod( pseudoDouble[i].c_str(), NULL );
    type      = TYPE_PSEUDOS;
    return ( TYPE_PSEUDOS );
  }
  return ( 0 );
}

int someRandomString( std::string toConvert ) {
  if ( toConvert.length() == 1 && !isdigit( *toConvert.c_str() ) && !isprint( *toConvert.c_str() ) ) {
	type = -1;
	return ( -1 );
  }
  if ( toConvert.length() > 1 && !pseudoLiterals(toConvert) ) {
	type = -1;
    return ( -1 );
  }
  return ( 0 );
}

void printPseudos() {
  std::cout << "Char: "
            << "impossible" << std::endl;
  std::cout << "Int: "
            << "impossible" << std::endl;
  std::cout << "Float: " << theFloat << "f" << std::endl;
  std::cout << "Double: " << theDouble << std::endl;
  return;
}

int parseString( std::string toConvert ) {
  if ( toConvert.empty() )
    return ( -1 );
  else if ( toConvert.length() == 1 && ( single( toConvert ) != -1 ) )
    return ( type );
  else if ( pseudoLiterals( toConvert ) == TYPE_PSEUDOS )
    return ( type );
  else if ( someRandomString( toConvert ) == -1 )
	return ( 0 );

  double temp = strtod( toConvert.c_str(), NULL );

  if ( temp == HUGE_VAL || temp == -HUGE_VAL )
    return ( -1 );
  if ( checkDigit( temp, toConvert ) || errno == ERANGE || errno == EDOM || errno == EILSEQ )
    return ( -1 );
  if ( checkInt( temp, toConvert ) == TYPE_INT )
    return ( type );
  else if ( checkFloat( temp, toConvert ) == TYPE_FLOAT )
    return ( type );
  else if ( checkDouble( temp, toConvert ) == TYPE_DOUBLE )
    return ( type );
  return ( 0 );
}

ScalarConverter::ScalarConverter( void ) {
  return;
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
  *this = src;
  return;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &assign ) {
  ( void ) assign;
  return ( *this );
}

ScalarConverter::~ScalarConverter( void ) {
  return;
}

void ScalarConverter::convert( std::string toConvert ) {
  parseString( toConvert );
  switch ( type ) {
    case TYPE_CHAR:
      fromChar();
      break;

    case TYPE_INT:
      fromInt();
      break;

    case TYPE_FLOAT:
      fromFloat();
      break;

    case TYPE_DOUBLE:
      fromDouble();
      break;

    case TYPE_PSEUDOS:
      printPseudos();
      break;

    default:
      std::cerr << "Invalid." << std::endl;
  }
  return;
}
