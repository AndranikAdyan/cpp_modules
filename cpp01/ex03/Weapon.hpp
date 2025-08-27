#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	
	private:
		std::string type;

	public:
		const std::string& getType() const;
		void setType(std::string type_);

		Weapon(std::string type_);
		~Weapon();
};

#endif