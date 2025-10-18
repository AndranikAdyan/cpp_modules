#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	srand(time(NULL));

	Bureaucrat low("LowRank", 150);
	Bureaucrat mid("MidRank", 100);
	Bureaucrat high("HighRank", 1);
	Intern intern;

	std::string formNames[3] = {
		"asdf",
		"robotomy request",
		"presidential pardon"
	};
	std::string targets[3] = {
		"Home",
		"Marvin",
		"Arthur"
	};

	AForm* form = NULL;

	for (int i = 0; i < 3; ++i) {
		try {
			form = intern.makeForm(formNames[i], targets[i]);
			std::cout << *form << std::endl;

			if (i == 0)
				mid.signForm(*form);
			else if (i == 1)
				high.signForm(*form);
			else
				high.signForm(*form);

			Bureaucrat* executors[3] = { &low, &mid, &high };
			for (int j = 0; j < 3; ++j) {
				try {
					executors[j]->executeForm(*form);
				} catch (std::exception &e) {
					std::cout << executors[j]->getName()
							  << " couldn't execute "
							  << form->getName()
							  << " because "
							  << e.what() << std::endl;
				}
			}

			delete form;
			form = NULL;
		} catch (std::exception &e) {
			std::cout << "Intern failed to create form '" 
					  << formNames[i] << "' because " 
					  << e.what() << std::endl;
		}
		std::cout << "-------------------------------------\n";
	}

	return 0;
}
