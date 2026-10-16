#include "PhoneBook.hpp"

std::string PhoneBook::getFirstName(int id) {
	return (Contacts[id].getFirstName());
}

std::string PhoneBook::getLastName(int id) {
	return (Contacts[id].getLastName());
}

std::string PhoneBook::getNickName(int id) {
	return (Contacts[id].getNickName());
}

void
PhoneBook::setContactId(int id, std::string first, std::string last, std::string nick, std::string phone,std::string secret) {
	Contacts[id].setContact(first, last, nick, phone, secret);
}

void PhoneBook::printContactId(int id) {
	Contacts[id].printContact();
}

int PhoneBook::isContactUsed(int id) {
	return (Contacts[id].contactExists());
}

void TruncateAndReplace(std::string &str) {
	if (str.length() > mlen) {
		str.resize(mlen - 1);
		str += ".";
	}
}

void PhoneBook::listPhoneBook() {
	std::string separator = "+----------+----------+----------+----------+\n";
	std::cout << separator
		    << std::right
		    << "|" << std::setw(10) << "Index"
		    << "|" << std::setw(10) << "First Name"
		    << "|" << std::setw(10) << "Last Name"
		    << "|" << std::setw(10) << "Nick Name"
		    << "|\n" << separator;
	for (int id = 0; Contacts[id].contactExists(); id++) {
		std::string firstname = getFirstName(id);
		TruncateAndReplace(firstname);
		std::string lastname = getLastName(id);
		TruncateAndReplace(lastname);
		std::string nickname = getNickName(id);
		TruncateAndReplace(nickname);
		std::cout << "|" << std::setw(10) << id
			    << "|" << std::setw(10) << firstname
			    << "|" << std::setw(10) << lastname
			    << "|" << std::setw(10) << nickname
			    << "|" << std::endl;
	}
	std::cout << separator;
}

