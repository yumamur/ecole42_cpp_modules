#ifndef HARL_H
#define HARL_H

#include <string>
#pragma once

class Harl {
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
