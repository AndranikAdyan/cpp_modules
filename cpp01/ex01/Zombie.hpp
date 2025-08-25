#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void set_name(std::string name);
		void announce(void);

	private:
		std::string name;

};

Zombie* zombieHorde(int N, std::string name);
