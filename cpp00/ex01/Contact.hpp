#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class Contact {

	public:
		Contact();

		Contact(const std::string first_name, const std::string last_name,
			const std::string nickname, const std::string phone_number,
			const std::string darkest_secret);

		~Contact();

		Contact get_contact();
		void display_summery() const;
		void display_full() const;
		Contact& operator=(const Contact& other);
		Contact(const Contact&);

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif