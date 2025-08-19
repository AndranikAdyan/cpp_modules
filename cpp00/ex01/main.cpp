#include "Contact.hpp"
#include "PhoneBook.hpp"

bool safe_input(const std::string& str, std::string& buff, int (*f)(int)) {
	std::cout << str << ": ";
	if (std::cin.peek() == '\n') {
		std::cin.get();
		return false;
	}
	std::getline(std::cin, buff);
	if (std::cin.eof() || std::cin.bad() || std::cin.fail())
		return false;
	for (size_t i = 0; i < buff.length(); i++)
		if (!f(buff[i]))
			return false;
	return true;
}

int secret_checker(int c) {
	return isalnum(c) || isspace(c);
}

bool get_contact(Contact& contact) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	if (!safe_input("Write First Name", first_name, isalpha)
		|| !safe_input("Write Last Name", last_name, isalpha)
		|| !safe_input("Write Nickname", nickname, isalnum)
		|| !safe_input("Write Phone Number", phone_number, isdigit)
		|| !safe_input("Write Darkest Secret", darkest_secret, secret_checker))
		return false;
	
	contact = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	return true;
}

int main() {
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		std::cout << "Input command: ";
		if (std::cin.peek() == '\n')
		{
			std::cin.get();
			continue;
		}
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail())
			break;
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Miqo?" << std::endl;
	}
	return 0;
}
