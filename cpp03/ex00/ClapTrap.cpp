#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unknown"), hp(10), energy(10), damage(0) {};

ClapTrap::ClapTrap(std::string name_) : name(name_), hp(10), energy(10), damage(0) {};

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->damage= other.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hp = other.hp;
	this->energy = other.energy;
	this->damage= other.damage;
	return *this;
}

ClapTrap::~ClapTrap() {};
