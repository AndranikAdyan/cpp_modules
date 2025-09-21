#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _inventory[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource&	operator=(const MateriaSource&);

		void	learnMateria(AMateria*);
		AMateria*	createMateria(const std::string&);
};
