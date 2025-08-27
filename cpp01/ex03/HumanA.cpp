#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon& weapon_) :
	name(name_),
	weapon(weapon_) {};

HumanA::~HumanA() {};

void HumanA::attack() const {
	std::cout << " attacks with their " << weapon.getType() << std::endl;
}
