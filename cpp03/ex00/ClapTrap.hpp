#include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			hp;
		int			energy;
		int			damage;

	public:
		ClapTrap();
		ClapTrap(std::string name_);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
