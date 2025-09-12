#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Unknown"), _hp(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap " << this->_name
				<< " was created!"<< std::endl;
};

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hp(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap " << this->_name
				<< " was created!" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_damage= other._damage;
	std::cout << "ClapTrap " << this->_name
				<< " was copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap " << this->_name
				<< " has been assigned from " << other._name
				<< " (copy assignment operator called)" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_energy = other._energy;
	this->_damage= other._damage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name
				<< " was destroyed!" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
	if (this->_hp <= 0) {
		std::cout << "ClapTrap " << this->_name
					<< " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name
					<< " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	--this->_energy;
	std::cout << "ClapTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_damage
				<< " points of damage! "
				<< "Current HP: " << this->_hp
				<< ", Energy: " << this->_energy
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " is already destroyed and cannot take more damage!"
					<< std::endl;
		return ;
	}
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name
		<< " takes " << amount
		<< " points of damage!"
		<< " Current HP: " << this->_hp << std::endl;
	if (this->_hp <= 0) {
		std::cout << "ClapTrap " << this->_name
					<< " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp <= 0) {
		std::cout << "ClapTrap " << this->_name 
					<< " has no hit points left and cannot repair!" 
					<< std::endl;
		return;
	}
	if (this->_energy <= 0) {
		std::cout << "ClapTrap " << this->_name
					<< " has no energy points left and cannot repair!"
					<< std::endl;
		return;
	}
	--this->_energy;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name
				<< " repairs itself, regaining " << amount
				<< " hit points! "
				<< "Current HP: " << this->_hp
				<< ", Energy: " << this->_energy
				<< std::endl;
}
