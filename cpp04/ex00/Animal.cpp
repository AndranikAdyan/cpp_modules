#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Some generic animal sound" << std::endl;
}
