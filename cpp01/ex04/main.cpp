#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int read_and_write( std::ifstream *in_file,
					std::ofstream *out_file,
					char		   to_find[],
					char		   to_set[] ) {
	size_t	l_size = strlen( to_find );
	char	buffer[l_size * 10 + 1];
	char   *ptr;
	ssize_t offset;
	size_t	len_of_to_move;

	in_file->get( buffer, l_size * 4 + 1, 0 );
	while ( true ) {
		ptr	   = std::strstr( buffer, to_find );
		offset = strlen( buffer ) - l_size;
		// std::cout << buffer << std::endl;

		if ( ptr ) {
			out_file->write( buffer, ptr - buffer );
			out_file->write( to_set, strlen( to_set ) );

			len_of_to_move = strlen( ptr + strlen( to_set ) );
			memmove( buffer, ptr + l_size, len_of_to_move + 1 );

			memset( buffer + len_of_to_move, 0,
					l_size * 4 - len_of_to_move + 1 );

		} else if ( strlen( buffer ) > l_size && !in_file->eof() ) {
			out_file->write( buffer, offset );

			std::memmove( buffer, buffer + offset, l_size + 1 );

		} else if ( !in_file->eof() ) {
			in_file->get( buffer + strlen( buffer ),
						  l_size * 4 - strlen( buffer ) + 1, 0 );
		} else {
			out_file->write( buffer, strlen( buffer ) );

			break;
		}
	}
	return ( 0 );
}

int main( int argc, char *argv[] ) {
	if ( argc < 4 || !*argv[1] || !*argv[2] || !*argv[3] ) {
		return ( -1 );
	}

	std::ifstream in_file( argv[1], std::ios::binary );
	std::ofstream out_file( std::string( argv[1] ).append( ".replace" ).c_str(),
							std::ios::binary );

	if ( !in_file.is_open() || !out_file.is_open() )
		return ( -1 );

	read_and_write( &in_file, &out_file, argv[2], argv[3] );
	in_file.close();
	out_file.close();
}