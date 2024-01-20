#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : _index(-1) {}

PhoneBook PhoneBook::instance;

Contact	&PhoneBook::getCurrentRef() {
	this->_index += 1;
	this->_index %= 8;
	return this->_contacts[this->_index];
}

Contact *PhoneBook::getAllContacts(void) {
	return this->_contacts;
}

Contact	&PhoneBook::getContactByIndex(int index) {
	return this->_contacts[index];
}

bool	PhoneBook::isEmpty(void) {
	if (this->_contacts[0].getFirstName().empty())
		return true;
	else
		return false;
}
