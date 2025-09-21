#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete this->_inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i)
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other)
		for (int i = 0; i < 4; ++i) {
			delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* el) {
	if (!el)
		return ;
	for (int i = 0; i < 4; ++i)
		if (!this->_inventory[i]) {
			this->_inventory[i] = el;
			return ;
		}
	delete el;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; ++i)
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	return NULL;
}
