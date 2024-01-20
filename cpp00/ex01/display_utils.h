#ifndef DISPLAY_UTILS_H
# define DISPLAY_UTILS_H

#include <iostream>
#include "Contact.hpp"

void	displayFormattedRow(
	std::string,
	std::string,
	std::string,
	std::string);

template<typename T>
std::string	convertToString(T&);

void	displayHeader(void);
void	displayContactTable(Contact *);
void	displayContact(Contact &contact);

#endif
