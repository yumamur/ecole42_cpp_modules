#ifndef ENCORE_HPP
# define ENCORE_HPP

# include "PhoneBook.hpp"

class EncoreApp {
	private:
		PhoneBook& _phonebook;
		int	oprAdd(void);
		int oprSearch(void);
	public:
		EncoreApp();
		int	execute(std::string command);
};

static const char ENCORE_APP_PROMPT[] = "\033[31;1msomething\033[m > ";

#endif
