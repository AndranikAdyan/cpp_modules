#include "Cat.hpp"
#include "iostream"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
