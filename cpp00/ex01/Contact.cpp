#include "Contact.hpp"

const std::string Contact::getFirstName(void) {
	return (this->_firstName);
}

const std::string Contact::getLastName() {
	return (this->_lastName);
}

const std::string Contact::getNickname() {
	return (this->_nickname);
}

const std::string Contact::getPhoneNumber() {
	return (this->_phoneNumber);
}

const std::string Contact::getDarkestSecret() {
	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string str) {
	this->_firstName = str;
}

void Contact::setLastName(std::string str) {
	this->_lastName = str;
}

void Contact::setNickname(std::string str) {
	this->_nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
	this->_phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
	this->_darkestSecret = str;
}