#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const & type);
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);

		void use(ICharacter& target);
		AMateria* clone() const;
};
