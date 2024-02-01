#include "Point.hpp"

#include <iostream>

bool eval( Point const &ref,
           Point const &p1,
           Point const &p2,
           Point const &eval ) {
    Point p1Norm( ( Point & ) p1 - ( Point & ) ref );
    Point p2Norm( ( Point & ) p2 - ( Point & ) ref );
    Point evalNorm( ( Point & ) eval - ( Point & ) ref );

    Fixed dist  = Point::magnR( evalNorm );
    Fixed other = Point::magnR( ( p1Norm + p2Norm ) - evalNorm );

    std::cout << "dist: " << dist << std::endl;
    std::cout << "other: " << other << std::endl;

    return dist != 0 && dist < other;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "p: " << point << std::endl;

    bool res1 = eval( a, b, c, point );
    bool res2 = eval( b, a, c, point );
    bool res3 = eval( c, b, a, point );

    return res1 && res2 && res3;
}
