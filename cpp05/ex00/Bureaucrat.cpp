#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) 
{
	// std::cout << "Bureaucrat: " << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
	// std::cout << "Bureaucrat: " << _name << " initialize constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
						_name(other._name), _grade(other._grade) 
						{
	// std::cout << "Bureaucrat: " << _name << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
	// std::cout << "Bureaucrat: " << _name << " desctructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) 
{
	// std::cout << "Bureaucrat: " << _name << " copy cnstructor called" << std::endl;
	if (this != &other) 
	{
		this->_grade = other.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName() const 
{
	return this->_name;
}

int			Bureaucrat::getGrade() const 
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade() 
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void		Bureaucrat::decrementGrade() 
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

