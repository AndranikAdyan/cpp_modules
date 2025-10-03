#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Bzzzz... brrrrr... *drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->target << "..." << std::endl;
}
