#include "Dog.hpp"
#include "iostream"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
