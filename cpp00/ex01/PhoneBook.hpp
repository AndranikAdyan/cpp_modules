#ifndef PHONEBOOK_HPP
# define PHONEBOBOK_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "Contact.hpp"

bool get_contact(Contact& contact);

class PhoneBook {
	public:
		void add_contact();
		void search();

	private:
		Contact contacts[8];
		int contacts_count;
};

#endif