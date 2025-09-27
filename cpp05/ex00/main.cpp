#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat1("Bob", 150);
		std::cout << bureaucrat1 << std::endl;

		bureaucrat1.increment();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.decrement();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.decrement();
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat2("Alex", 3);
		std::cout << bureaucrat2 << std::endl;

		bureaucrat2.increment();
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.increment();
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.increment();
		std::cout << bureaucrat2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception (too high): " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception (too low): " << e.what() << std::endl;
	}

	return 0;
}
