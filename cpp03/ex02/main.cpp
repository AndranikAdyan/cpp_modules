#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "===== Testing ClapTrap =====" << std::endl;

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

	std::cout << "===== Testing FragTrap =====" << std::endl;

	FragTrap fraggy("Fraggy");
	fraggy.attack("EnemyBot");
	fraggy.takeDamage(40);
	fraggy.beRepaired(25);
	fraggy.highFivesGuys();

	FragTrap fragCopy(fraggy);
	FragTrap fragAssign;
	fragAssign = fraggy;

	
	for (int i = 0; i < 105; ++i)
		fraggy.attack("EnemyBot");

	std::cout << "===== Virtual Function Test =====" << std::endl;

	ClapTrap* ptr1 = new ClapTrap("Clappy");
	ClapTrap* ptr2 = new ScavTrap("Scavvy");
	ClapTrap* ptr3 = new FragTrap("FraggyVirt");

	std::cout << std::endl << "-- Attacks through ClapTrap pointers --" << std::endl;
	ptr1->attack("Target1");
	ptr2->attack("Target2");
	ptr3->attack("Target3");

	std::cout << std::endl << "-- Clean up --" << std::endl;
	delete ptr1;
	delete ptr2;
	delete ptr3;

	std::cout << "===== End of Test =====" << std::endl;

	return 0;
}
