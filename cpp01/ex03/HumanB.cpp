#include "HumanB.hpp"

HumanB::HumanB(std::string name_) : name(name_) {};

void HumanB::setWeapon(Weapon *weapon_) {
	this->weapon = weapon_;
}

HumanB::~HumanB() {};

void HumanB::attack() const {
	std::cout << " attacks with their " << weapon->getType() << std::endl;
}
