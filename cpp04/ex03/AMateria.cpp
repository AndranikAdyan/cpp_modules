#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "unknown";
}

AMateria::AMateria(std::string const & type) : _type(type) {};

AMateria::~AMateria() {};

AMateria::AMateria(const AMateria& other) {
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {(void) target;}
