#include "Zombie.hpp"

int main()
{
	Zombie *arr;

	arr = zombieHorde(10, "Vardanush");
	delete[] arr;
	return 0;
}
