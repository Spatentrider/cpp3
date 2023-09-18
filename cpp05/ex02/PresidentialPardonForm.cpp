#include "PresidentialPardonForm.hpp"

President::President() :
		AForm("President", 25, 5), _target("President") {
	// std::cout << "President: constructor called" << std::endl;
}

President::President(const std::string& target) :
		AForm("President_" + target, 25, 5), _target(target) {
	// std::cout << "President: initialize constructor called" << std::endl;
}

President::President(const President& other) :
		AForm(other), _target(other._target) {
	// std::cout << "President: copy constructor called" << std::endl;
}

President& President::operator=(const President& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

President::~President() {
	// std::cout << "President: desctructor called" << std::endl;
}

void President::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::NotSignedException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
