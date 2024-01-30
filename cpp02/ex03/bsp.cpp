#include "Point.hpp"

bool eval( Point const &ref,
           Point const &p1,
           Point const &p2,
           Point const &eval ) {
    Point p1Norm( ( Point & ) p1 - ( Point & ) ref );
    Point p2Norm( ( Point & ) p2 - ( Point & ) ref );
    Point evalNorm( ( Point & ) eval - ( Point & ) ref );

    Fixed dist  = Point::magnR( evalNorm );
    Fixed other = Point::magnR( ( p1Norm + p2Norm ) - evalNorm );

    if ( dist < other ) {
        return true;
    } else {
        return false;
    }
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    bool res = eval( a, b, c, point ) && eval( b, a, c, point ) &&
               eval( c, b, a, point );
    return res;
}