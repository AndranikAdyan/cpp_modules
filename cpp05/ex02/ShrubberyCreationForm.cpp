#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	
	std::ofstream o_file((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!o_file.is_open())
		throw std::runtime_error("Failed to open file for shrubbery creation");
	o_file <<	"     ccee88oo\n"
				"  C8O8O8Q8PoOb o8oo\n"
				" dOB69QO8PdUOpugoO9bD\n"
				"CgggbU8OU qOp qOdoUOdcb\n"
				"    6OuU  /p u gcoUodpP\n"
				"  \\\\\\\\//  /douUP\n"
				"    \\\\\\\\////\n"
				"         |||/\n"
				"         |||\n"
				"         |||\n"
				"   .....//|||\\\\\\\\....\n";
	
	o_file.close();
}
