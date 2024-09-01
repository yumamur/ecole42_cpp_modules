#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
  private:
    unsigned int     _cap;
    unsigned int     _size;
    std::vector<int> _arr;

  public:
    Span( unsigned int n );
    Span( Span const &other );
    Span &operator=( Span const &other );
    ~Span();
    void         addNumber( int n );
    void         addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );
    unsigned int shortestSpan();
    unsigned int longestSpan();

    void         forEach( void ( *f )( int ) );
};

#endif       // !SPAN_HPP
