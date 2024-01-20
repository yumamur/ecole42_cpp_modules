#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        PhoneBook();
        Contact _contacts[8];
        int _index;
    public:
        static PhoneBook instance;
        Contact &getCurrentRef(void);
        Contact *getAllContacts(void);
        Contact &getContactByIndex(int);
        bool isEmpty(void);
};

#endif
