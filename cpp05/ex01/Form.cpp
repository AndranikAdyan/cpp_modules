#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Form::Form()
	: m_name("unknown"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
		: m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	if (this->m_gradeToSign < 1 || this->m_gradeToExecute < 1) throw Form::GradeTooHighException();
	if (this->m_gradeToSign > 150 || this->m_gradeToExecute > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	this->m_isSigned = other.m_isSigned;
	return *this;
}

std::string	Form::getName() const {
	return this->m_name;
}

bool Form::getIsSigned() const {
	return this->m_isSigned;
}

int Form::getGradeToSign() const {
	return this->m_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->m_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	this->m_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "Form " << obj.getName() << " [sign grade: " << obj.getGradeToSign()
		<< ", execute grade: " << obj.getGradeToExecute() << ", signed: "
		<< (obj.getIsSigned() ? "yes" : "no") << "]";
	return out;
}

Form::~Form() {}
