#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

AForm::AForm()
	: m_name("unknown"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
		: m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	if (this->m_gradeToSign < 1 || this->m_gradeToExecute < 1) throw AForm::GradeTooHighException();
	if (this->m_gradeToSign > 150 || this->m_gradeToExecute > 150) throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: m_name(other.m_name), m_isSigned(other.m_isSigned), m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	this->m_isSigned = other.m_isSigned;
	return *this;
}

std::string	AForm::getName() const {
	return this->m_name;
}

bool AForm::getIsSigned() const {
	return this->m_isSigned;
}

int AForm::getGradeToSign() const {
	return this->m_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->m_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	this->m_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "Form " << obj.getName() << " [sign grade: " << obj.getGradeToSign()
		<< ", execute grade: " << obj.getGradeToExecute() << ", signed: "
		<< (obj.getIsSigned() ? "yes" : "no") << "]";
	return out;
}

AForm::~AForm() {}
