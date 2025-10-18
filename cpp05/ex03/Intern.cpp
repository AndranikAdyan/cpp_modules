#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstring>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

const char* Intern::InternNotFound::what() const throw() {
	return "Intern not found";
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	if (formName == "shrubbery creation") {
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request") {
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon") {
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	}
	throw InternNotFound();
	return NULL;
}
