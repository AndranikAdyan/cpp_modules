#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	zombie = newZombie("Vzgo");
	delete zombie;
	randomChump("Bob");
	return 0;
}
