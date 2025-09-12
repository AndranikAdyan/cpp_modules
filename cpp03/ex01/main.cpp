#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ClapTrap alpha("Alpha");
	alpha.attack("Target1");
	alpha.takeDamage(3);
	alpha.beRepaired(5);
	alpha.takeDamage(20);
	alpha.attack("Target2");
	alpha.beRepaired(5);

	std::cout << "=============================" << std::endl;

	ClapTrap beta(alpha);
	ClapTrap gamma;
	gamma = alpha;

	std::cout << "===== Testing ScavTrap =====" << std::endl;

	ScavTrap delta("Delta");
	delta.attack("Dummy");
	delta.takeDamage(30);
	delta.beRepaired(20);
	delta.guardGate();

	for (int i = 0; i < 55; ++i)
		delta.attack("Dummy");

	std::cout << "=============================" << std::endl;

	ScavTrap epsilon(delta);
	ScavTrap zeta;
	zeta = delta;

	std::cout << "===== End of Test =====" << std::endl;

	return 0;
}
