#include "Harl.h"
int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		return ( 0 );
	}
	Harl harl;
	harl.complain( argv[1] );
}