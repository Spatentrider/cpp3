#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog   : " << _type << " constructor called " << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) 
{
	std::cout << "Dog   : " << _type << " copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() 
{
	std::cout << "Dog   : " << _type << " destructor called" << std::endl;
	delete(_brain);
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog   : " << _type << " copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Dog::makeSound() const 
{
	std::cout << "Dog   : " << _type << ": Baauuuu Baauuu!!!" << std::endl;
}




