#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap a("Alpha");

	a.attack("Target1");

	a.takeDamage(3);

	a.beRepaired(5);

	a.takeDamage(20);
	a.attack("Target2");
	a.beRepaired(5);

	std::cout << "=============================" << std::endl;

	ClapTrap b(a);

	ClapTrap c("Charlie");
	c = a;

	std::cout << "=============================" << std::endl;

	ClapTrap d("Delta");
	for (int i = 0; i < 12; ++i) {
		d.attack("Dummy");
	}

	return 0;
}
