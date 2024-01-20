#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include "display_utils.h"
#include "EncoreApp.hpp"
#include "PhoneBook.hpp"

EncoreApp::EncoreApp() : _phonebook(PhoneBook::instance) {
    std::cout << "Initializing nothing" << std::endl;
	this->_phonebook = PhoneBook::instance;
}

bool isNotEmpty(std::string str) {
    return !str.empty();
}

bool validateIndexInput(int i) {
    return (i >= 1 && i <= 8
                ? true
                : false
            );
}

template <typename T>
T waitValidInput(
    std::string prompt,
    bool (*validate)(T),
    T (*converter)(const char *)) {
    std::string input;
    T result;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            throw std::exception();
        result = converter(input.data());
        if (validate(result))
            return (result);
    }
}

static std::string convertCharPtrToString(const char *ptr) {
    return std::string(ptr);
}

int EncoreApp::oprAdd() {
    Contact &ref = this->_phonebook.getCurrentRef();

    ref.setFirstName(waitValidInput(
        "First name for the new contact: ",
        isNotEmpty,
        convertCharPtrToString));
    ref.setLastName(waitValidInput(
        "Lastname of " + ref.getFirstName() + ": ",
        isNotEmpty,
        convertCharPtrToString));
    ref.setNickname(waitValidInput(
        "What would you call " + ref.getFirstName() + ": ",
        isNotEmpty,
        convertCharPtrToString));
    ref.setPhoneNumber(waitValidInput(
        "Now, we need " + ref.getFirstName() + "'s phone number: ",
        isNotEmpty,
        convertCharPtrToString));
    ref.setDarkestSecret(waitValidInput(
        "What is " + ref.getFirstName() + " losing sleeps over: ",
        isNotEmpty,
        convertCharPtrToString));
    return (0);
}

int EncoreApp::oprSearch() {
    if (this->_phonebook.isEmpty()) {
        std::cout << "Contact table is empty." << std::endl;
        return (0);
    }
    displayContactTable(this->_phonebook.getAllContacts());
    int index = waitValidInput(
        "Enter an index between 1-8: ",
        validateIndexInput,
        std::atoi);
    displayContact(this->_phonebook.getContactByIndex(index - 1));
    return (0);
}

int EncoreApp::execute(std::string command) {
    try {
        if (command == "EXIT") {
            return (1);
        } else if (command == "ADD") {
            return (oprAdd());
        } else if (command == "SEARCH") {
            return (oprSearch());
        } else {
            return (0);
        }
    } catch (std::exception const &) {
        return (-1);
    }
}
