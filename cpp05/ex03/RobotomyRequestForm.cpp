#include "RobotomyRequestForm.hpp"

Robotomy::Robotomy() : AForm("Robotomy", 72, 45), _target("Robotomy") 
{
	// std::cout << "Robotomy: constructor called" << std::endl;
}

Robotomy::Robotomy(const std::string& target) : AForm("Robotomy_" + target, 72, 45), _target(target) 
{
	// std::cout << "Robotomy: initialize constructor called" << std::endl;
}

Robotomy::Robotomy(const Robotomy& other) : AForm(other), _target(other._target) 
{
	// std::cout << "Robotomy: copy constructor called" << std::endl;
}

Robotomy& Robotomy::operator=(const Robotomy& other) 
{
	if (this != &other) 
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

Robotomy::~Robotomy() 
{
	// std::cout << "Robotomy: destructor called" << std::endl;
}

void	Robotomy::execute(Bureaucrat const& executor) const 
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::NotSignedException();
	std::srand(static_cast<unsigned>(time(0)));
    int randomValue = std::rand() % 2;
    if (randomValue == 0)
		std::cout << "Vrrrrrrrrrrrrrrrrrr! " << executor.getName() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << executor.getName() << ": robotomy failed.." << std::endl;
	i++;
}
