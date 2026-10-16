#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "ContactBook.hpp"

class PhoneBook{
    
    private:
        Contact Contacts[mid];

        std::string getFirstName(int id);

        std::string getLastName(int id);

        std::string getNickName(int id);

    public:
        void setContactId(int id, std::string first, std::string last, std::string nick, std::string phone, std::string secret);

        void printContactId(int id);

        int isContactUsed(int id);

        void listPhoneBook();
};


#endif