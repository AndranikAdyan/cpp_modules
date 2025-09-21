#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const & type) : AMateria(type) {};

Ice::~Ice() {};

Ice::Ice(const Ice& other) : AMateria() {
	this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}
