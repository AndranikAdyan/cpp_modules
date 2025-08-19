#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

Contact::Contact(const std::string first_name, const std::string last_name,
			const std::string nickname, const std::string phone_number,
			const std::string darkest_secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void Contact::display_summery() const {
	std::cout << std::right;
	std::cout << std::setw(10) << first_name << "|";
	std::cout << std::setw(10) << last_name << "|";
	std::cout << std::setw(10) << nickname << "|" << std::endl;
	std::cout.flags(std::ios::fmtflags(0));
}

void Contact::display_full() const {
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this == &other)
		return *this;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nickname = other.nickname;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
	return *this;
}
