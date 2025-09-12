#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("UnknownFrag") {
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name
				<< " was created!"<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name
				<< " was created!"<< std::endl;	
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << this->_name
				<< " was copied!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " was destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << this->_name
				<< " has been assigned from " << other._name
				<< " (copy assignment operator called)" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (this->_hp <= 0) {
		std::cout << "ScavTrap " << this->_name
					<< " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (this->_energy <= 0) {
		std::cout << "ScavTrap " << this->_name
					<< " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	--this->_energy;
	std::cout << "FragTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_damage
				<< " points of damage! "
				<< "Current HP: " << this->_hp
				<< ", Energy: " << this->_energy
				<< std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name
				<< " requests a high five!" << std::endl;
}