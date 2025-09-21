#include "Brain.hpp"
#include "iostream"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return *this;
}
