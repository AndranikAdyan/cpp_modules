#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("DiamondUnknown_clap_name"),
							ScavTrap("DiamondUnknown"),
							FragTrap("DiamondUnknown"),
							name("DiamondUnknown") {
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << this->name << " was created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name + "_clap_name"),
													ScavTrap(_name),
													FragTrap(_name),
													name(_name)
{
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << this->name << " was created!" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
													ScavTrap(other),
													FragTrap(other),
													name(other.name)
{
	ClapTrap::_name = other.ClapTrap::_name;
	std::cout << "DiamondTrap " << this->name << " was copied!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " was destroyed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ClapTrap::_name = other.ClapTrap::_name;
		std::cout << "DiamondTrap " << this->name
				  << " has been assigned from " << other.name
				  << " (copy assignment operator called)" << std::endl;
	}
	return *this;
}


void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->name
			  << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
