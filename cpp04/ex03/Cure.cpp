#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const & type) : AMateria(type) {};

Cure::~Cure() {};

Cure::Cure(const Cure& other) : AMateria() {
	this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}
