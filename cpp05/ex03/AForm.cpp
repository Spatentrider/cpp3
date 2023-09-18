#include "AForm.hpp"

AForm::AForm() :
		_name("1A"), _signed(false), _gradeToSign(150),
		_gradeToExecute(150) {
	// std::cout << "AForm: " << _name << " constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
		_name(name), _signed(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute) {
	// std::cout << "AForm: " << _name << " initialize constructor called" << std::endl;
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
		throw GradeTooHighException();
	else if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :
		_name(other._name), _signed(other._signed),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute) {
	// std::cout << "AForm: " << _name << " copy constructor called" << std::endl;
}

AForm::~AForm() {
	// std::cout << "AForm: " << _name << " desctructor called" << std::endl;
}

AForm&		AForm::operator=(const AForm& other) {
	// std::cout << "AForm: " << _name << " copy constructor called" << std::endl;
	if (this != &other) {
		this->_signed = other.getSigned();
	}
	return *this;
}

std::string	AForm::getName() const {
	return this->_name;
}

bool		AForm::getSigned() const {
	return this->_signed;
}

int			AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int			AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void		AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "\033[0;31mForm: grade is too high\033[0m";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "\033[0;31mForm: grade is too low\033[0m";
}

const char* AForm::NotSignedException::what() const throw() {
	return "\033[0;31mForm: this form is not signed\033[0m";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << form.getName() << ", is signed? " << form.getSigned()
		<< "\nGrade to signed required " << form.getGradeToSign()
		<< "\nGrade to execute required " << form.getGradeToExecute();
	return out;
}
