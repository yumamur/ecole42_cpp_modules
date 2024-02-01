/*   By: lrocca */

#include "Point.hpp"

#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point );

int  main( void ) {
    std::cout
        << std::boolalpha

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ), Point( 1, 1 ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ), Point( 0, 5 ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ), Point( 1, 3 ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ), Point( 0, 0 ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ),
                 Point( 0.1f, 0.01f ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ),
                 Point( 10, 0.01f ) )
        << std::endl
        << std::endl

        << bsp( Point( 0, 0 ), Point( 0, 5 ), Point( 5, 0 ),
                 Point( 0, -0.01f ) )
        << std::endl;
}
