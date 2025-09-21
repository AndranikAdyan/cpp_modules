#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);

		void use(ICharacter& target);
		AMateria* clone() const;
};
