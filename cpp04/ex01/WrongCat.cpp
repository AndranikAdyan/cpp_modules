#include "WrongCat.hpp"
#include "iostream"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
