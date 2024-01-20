#include <sstream>
#include <iostream>
#include "Contact.hpp"

template<typename T>
std::string	convertToString(T& obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

static void displayFormattedCell(std::string str) {
	if (str.empty())
		return ;
	std::cout << "|";
	if (str.length() <= 10) {
		for (unsigned long i = 0; i < 10 - str.length(); ++i)
			std::cout << " ";
		std::cout << str;
	} else {
		std::cout << str.substr(0, 9) << ".";
	}
}

static void	displayFormattedRow(
	std::string str0,
	std::string str1,
	std::string str2,
	std::string str3) {
		displayFormattedCell(str0);
		displayFormattedCell(str1);
		displayFormattedCell(str2);
		displayFormattedCell(str3);
		std::cout << "|" << std::endl;
}

void	displayHeader(void) {
	std::cout << "=============================================" << std::endl;
	displayFormattedRow(
			"Index",
			"First Name",
			"Last Name",
			"NickName"
		);
}

void	displayFooter(void) {
	std::cout << "=============================================" << std::endl;
}

void	displayContactTable(Contact *table) {
	displayHeader();
	for (int i = 1; i <= 8; ++i) {
		if (table[i - 1].getFirstName().empty())
			break ;
		displayFormattedRow(
				convertToString(i),
				table[i - 1].getFirstName(),
				table[i - 1].getLastName(),
				table[i - 1].getNickname()
			);
	}
	displayFooter();
}

void displayContact(Contact &contact) {
	if (contact.getFirstName().empty()) {
		std::cout << "This contact has not yet been initialized" << std::endl;
		return ;
	}
	std::cout << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}
