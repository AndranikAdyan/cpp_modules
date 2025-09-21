#include "Character.hpp"

Character::Character() : _name("Unknown"), _slots_number(4) {
	for (int i = 0; i < _slots_number; i++)
		_slots[i] = NULL;
}

Character::Character(std::string name) : _name(name), _slots_number(4) {
	for (int i = 0; i < _slots_number; i++)
		_slots[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _slots_number(4) {
	for (int i = 0; i < _slots_number; ++i) {
		if (other._slots[i])
			_slots[i] = other._slots[i]->clone();
		else
			_slots[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this == &other)
		return *this;

	_name = other._name;

	for (int i = 0; i < _slots_number; ++i) {
		if (_slots[i]) {
			delete _slots[i];
			_slots[i] = NULL;
		}
	}

	for (int i = 0; i < _slots_number; ++i) {
		if (other._slots[i])
			_slots[i] = other._slots[i]->clone();
		else
			_slots[i] = NULL;
	}

	return *this;
}

Character::~Character() {
	for (int i = 0; i < _slots_number; ++i)
		delete _slots[i];
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < _slots_number; i++) {
		if (_slots[i] == NULL) {
			_slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= _slots_number)
		return;
	_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _slots_number)
		return;
	if (_slots[idx])
		_slots[idx]->use(target);
}

AMateria* Character::getSlot(int idx) const {
	return this->_slots[idx];
}
