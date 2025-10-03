#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));

	Bureaucrat low("LowRank", 150);
	Bureaucrat mid("MidRank", 100);
	Bureaucrat high("HighRank", 1);

	Intern intern;

	AForm* shrub = intern.makeForm("shrubbery creation", "Home");
	AForm* robo = intern.makeForm("robotomy request", "Marvin");
	AForm* pardon = intern.makeForm("presidential pardon", "Arthur");

	std::cout << *shrub << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pardon << std::endl;

	low.signForm(*shrub);
	mid.signForm(*shrub);
	high.signForm(*robo);
	high.signForm(*pardon);

	Bureaucrat executors[] = { low, mid, high };
	AForm* forms[] = { shrub, robo, pardon };

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			try {
				executors[i].executeForm(*forms[j]);
			} catch (std::exception &e) {
				std::cout << executors[i].getName() << " couldn't execute " 
						  << forms[j]->getName() << " because " 
						  << e.what() << std::endl;
			}
		}
	}

	delete shrub;
	delete robo;
	delete pardon;

	return 0;
}
