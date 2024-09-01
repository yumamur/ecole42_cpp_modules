#include "Span.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <unistd.h>

unsigned int getVariedSeed() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    unsigned int seed = tv.tv_usec + getpid();

    return seed;
}

void print( int n ) {
  std::cout << n << " ";
}

int generateRandomNumber() {
  return std::rand();
}

int main() {
  Span sp( 20000 );

  std::srand( static_cast<unsigned int>( std::time( NULL ) ) );

  std::vector<int> numbers( 20000 );
  std::generate( numbers.begin(), numbers.end(), generateRandomNumber );

  try {
    sp.addNumber( numbers.begin(), numbers.end() );
  } catch ( std::exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  } catch ( std::exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
