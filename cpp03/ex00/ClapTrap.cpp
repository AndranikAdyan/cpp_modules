#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Unknown"), hp(10), energy(10), damage(0) {
	std::cout << "ClapTrap " << this->name
				<< " was created!"<< std::endl;
};

ClapTrap::ClapTrap(std::string name_) : name(name_), hp(10), energy(10), damage(0) {
	std::cout << "ClapTrap " << this->name
				<< " was created!" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->damage= other.damage;
	std::cout << "ClapTrap " << this->name
				<< " was copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap " << this->name
				<< " has been assigned from " << other.name
				<< " (copy assignment operator called)" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->damage= other.damage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name
				<< " was destroyed!" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name
					<< " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (this->energy <= 0) {
		std::cout << "ClapTrap " << this->name
					<< " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	--this->energy;
	std::cout << "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->damage
				<< " points of damage! "
				<< "Current HP: " << this->hp
				<< ", Energy: " << this->energy
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name
					<< " is already destroyed and cannot take more damage!"
					<< std::endl;
		return ;
	}
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout << "ClapTrap " << this->name
		<< " takes " << amount
		<< " points of damage!"
		<< " Current HP: " << this->hp << std::endl;
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name
					<< " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name 
					<< " has no hit points left and cannot repair!" 
					<< std::endl;
		return;
	}
	if (this->energy <= 0) {
		std::cout << "ClapTrap " << this->name
					<< " has no energy points left and cannot repair!"
					<< std::endl;
		return;
	}
	--this->energy;
	this->hp += amount;
	std::cout << "ClapTrap " << this->name
				<< " repairs itself, regaining " << amount
				<< " hit points! "
				<< "Current HP: " << this->hp
				<< ", Energy: " << this->energy
				<< std::endl;
}
