#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== Test 1: Basic MateriaSource and Character ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	if (tmp) me->equip(tmp); else delete tmp;

	tmp = src->createMateria("cure");
	if (tmp) me->equip(tmp); else delete tmp;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n=== Test 2: Equip more than 4 Materias ===" << std::endl;
	tmp = src->createMateria("ice");
	if (tmp) me->equip(tmp); else delete tmp;

	tmp = src->createMateria("cure");
	if (tmp) me->equip(tmp); else delete tmp;

	tmp = src->createMateria("ice");
	if (tmp) {
		me->equip(tmp);
		bool equipped = false;
		for (int i = 0; i < 4; ++i) {
			if (((Character*)me)->getSlot(i) == tmp) equipped = true;
		}
		if (!equipped) delete tmp; // если не поместилось, удаляем
	}

	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "\n=== Test 3: Unequip and use ===" << std::endl;
	AMateria* saved = ((Character*)me)->getSlot(1);
	me->unequip(1);
	me->use(1, *bob);

	delete saved;

	tmp = src->createMateria("cure");
	if (tmp) me->equip(tmp); else delete tmp;
	me->use(1, *bob);

	std::cout << "\n=== Test 4: Deep copy of Character ===" << std::endl;
	Character* cloneMe = new Character(*(Character*)me);
	cloneMe->use(0, *bob);
	cloneMe->use(1, *bob);

	std::cout << "\n=== Test 5: Create unknown Materia ===" << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown == 0)
		std::cout << "Unknown Materia returned NULL as expected" << std::endl;

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete bob;
	delete me;
	delete cloneMe;
	delete src;

	return 0;
}
