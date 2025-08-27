#include "Weapon.hpp"

const std::string& Weapon::getType() const {
	const std::string& ref = this->type;
	return ref;
}

void Weapon::setType(std::string type_) {
	this->type = type_;
}

Weapon::Weapon(std::string type_) : type(type_) {};

Weapon::~Weapon() {};
