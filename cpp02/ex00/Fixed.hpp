#ifndef FIXED_H
#define FIXED_H

#pragma once

class Fixed {
	public:
		Fixed();
		Fixed( const Fixed &fixed );
		Fixed &operator=( const Fixed &fixed );
		~Fixed();
		int	 getRawBits( void ) const;
		void setRawBits( int const );

	private:
		int				 _fixed_point;
		static const int _fractional_bits = 8;
};

#endif