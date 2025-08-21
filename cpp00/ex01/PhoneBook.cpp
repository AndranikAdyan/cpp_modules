#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts_count(0) {};

void PhoneBook::add_contact() {
	
	if (contacts_count != 8 && get_contact(contacts[contacts_count]))
		++contacts_count;
	else if (contacts_count == 8) {
		for (int i = 0; i < contacts_count - 1; ++i)
			contacts[i] = contacts[i + 1];
		get_contact(contacts[contacts_count - 1]);
	}
}

void PhoneBook::search() {
	std::cout << std::right;
	std::cout << std::setw(11) << "Index|";
	std::cout << std::setw(11) << "First Name|";
	std::cout << std::setw(11) << "Last Name|";
	std::cout << std::setw(11) << "Nickname|" << std::endl;

	for (int i = 0; i < contacts_count; ++i) {
		std::cout << std::setw(10) << i + 1 << "|";
		contacts[i].display_summery();
	}
	std::cout.flags(std::ios::fmtflags(0));

	std::string user_input;
	std::cout << std::endl << "Enter the index of the contact you want to view: ";

	if (std::cin.peek() == '\n')
	{
		std::cin.get();
		return ;
	}
	std::getline(std::cin, user_input);

	for (size_t i = 0; i < user_input.length(); i++) {
		if (!isdigit(user_input[i])) {
			std::cout << "Invalid index." << std::endl;
			return;
		}
	}

	std::stringstream ss(user_input);
	int index;
	ss >> index;

	if (ss.fail() || index < 1 || index > this->contacts_count) {
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "Contact information:" << std::endl;
	contacts[index - 1].display_full();
	std::cout << std::endl;
}
