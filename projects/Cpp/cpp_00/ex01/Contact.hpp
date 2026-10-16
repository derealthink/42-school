#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

    private:
        std::string firstName;

        std::string lastName;

        std::string nickname;

        std::string phoneNumber;

        std::string darkestSecret;

        bool initialized;
    
    public:
        Contact() : initialized(false) {};

        void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
        
        void printContact(); 

        int contactExists();

        std::string getFirstName();

        std::string getLastName();

        std::string getNickName();
};

#endif