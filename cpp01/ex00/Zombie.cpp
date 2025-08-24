#include "Zombie.hpp"

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name_) {
	this->name = name_;
}

Zombie::~Zombie() {
	std::cout << this->name << ": died (again)" << std::endl;
}