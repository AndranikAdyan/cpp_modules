#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("UnknownScav") {
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name
				<< " was created!"<< std::endl;

}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name
				<< " was created!"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << this->_name
				<< " was copied!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << this->_name
				<< " has been assigned from " << other._name
				<< " (copy assignment operator called)" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
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
	std::cout << "ScavTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_damage
				<< " points of damage! "
				<< "Current HP: " << this->_hp
				<< ", Energy: " << this->_energy
				<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name
				<< " is now in Gate keeper mode." << std::endl;
}