#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high (less than 1)!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low (more than 150)!";
}

Bureaucrat::Bureaucrat() : m_name("Unknown"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade = grade;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name), m_grade(other.m_grade) {}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->m_grade = other.m_grade;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->m_name;
}
int Bureaucrat::getGrade() const {
	return this->m_grade;
}

void Bureaucrat::increment() {
	if (this->m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	--this->m_grade;
}

void Bureaucrat::decrement() {
	if (this->m_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	++this->m_grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}
