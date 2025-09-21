#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Some generic animal sound" << std::endl;
}
