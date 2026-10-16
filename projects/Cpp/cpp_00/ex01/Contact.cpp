#include "Contact.hpp"

void Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
    initialized = true;
}

void Contact::printContact() {
	std::cout << (firstName + "\n" + lastName + "\n" + nickname + "\n" + phoneNumber +"\n" + darkestSecret + "\n");
}

int Contact::contactExists() {
	return (initialized);
}

std::string Contact::getFirstName() {
	return (firstName);
}

std::string Contact::getLastName() {
	return (lastName);
}

std::string Contact::getNickName() {
	return (nickname);
}

