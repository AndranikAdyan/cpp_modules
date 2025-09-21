#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	Animal **animals = new Animal*[10];

	for (int i = 0; i < 5; ++i)
		animals[i] = new Dog();

	for (int i = 5; i < 10; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < 10; ++i)
		delete animals[i];

	delete[] animals;

	return 0;
}