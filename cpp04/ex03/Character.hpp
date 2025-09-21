#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _slots[4];
		int _slots_number;

	public:
		Character();
		Character(std::string name);
		Character(const Character& other);
		~Character();

		Character& operator=(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getSlot(int idx) const;
};

#endif
