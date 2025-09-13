#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Testing ClapTrap =====" << std::endl;
	ClapTrap clap("Alpha");
	clap.attack("Target1");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.takeDamage(20);
	clap.attack("Target2");
	clap.beRepaired(2);

	std::cout << "=============================" << std::endl;

	std::cout << "===== Testing ScavTrap =====" << std::endl;
	ScavTrap scav("Delta");
	scav.attack("Dummy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	scav.attack("Dummy");

	std::cout << "=============================" << std::endl;

	std::cout << "===== Testing FragTrap =====" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("EnemyBot");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();

	std::cout << "=============================" << std::endl;

	std::cout << "===== Testing DiamondTrap =====" << std::endl;
	DiamondTrap diamond("Diamondy");
	diamond.attack("EvilBot");
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.whoAmI();

	std::cout << "===== Copy constructor test =====" << std::endl;
	DiamondTrap copyDiamond(diamond);
	copyDiamond.whoAmI();
	copyDiamond.attack("CopyTarget");

	std::cout << "===== Assignment operator test =====" << std::endl;
	DiamondTrap assignDiamond("Assigny");
	assignDiamond = diamond;
	assignDiamond.whoAmI();
	assignDiamond.attack("AssignTarget");

	std::cout << "===== Virtual function test =====" << std::endl;
	ClapTrap* ptr1 = new ClapTrap("Clappy");
	ClapTrap* ptr2 = new ScavTrap("Scavvy");
	ClapTrap* ptr3 = new DiamondTrap("DiamondVirt");

	ptr1->attack("Target1");
	ptr2->attack("Target2");
	ptr3->attack("Target3");

	delete ptr1;
	delete ptr2;
	delete ptr3;

	std::cout << "===== End of Test =====" << std::endl;

	return 0;
}
