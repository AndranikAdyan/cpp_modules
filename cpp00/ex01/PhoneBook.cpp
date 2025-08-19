#include "PhoneBook.hpp"

void PhoneBook::add_contact() {
	if (contacts_count != 8 && get_contact(contacts[contacts_count]))
		++contacts_count;
	else {
		for (int i = 0; i < contacts_count - 1; ++i)
			contacts[i] = contacts[i + 1];
		get_contact(contacts[contacts_count]);
	}
}

void PhoneBook::search() {
	std::cout << std::right;
	std::cout << std::setw(11) << "Index|";
	std::cout << std::setw(11) << "First Name|";
	std::cout << std::setw(11) << "Last Name|";
	std::cout << std::setw(11) << "Nickname|" << std::endl;
	for (int i = 0; i < contacts_count; ++i)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		contacts[i].display_summery();
	}
	std::cout.flags(std::ios::fmtflags(0));
}
