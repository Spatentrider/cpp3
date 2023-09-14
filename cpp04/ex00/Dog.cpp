#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog   : " << _type << " constructor called " << std::endl;
}

Dog::Dog(const Dog &other) 
{
	std::cout << "Dog   : " << _type << " copy costructor called" << std::endl;
	*this = other;
}

Dog::~Dog() 
{
	std::cout << "Dog   : " << _type << " destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog   : " << _type << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void	Dog::makeSound() const 
{
	std::cout << "Dog   : " << _type << ": Baauuuu Baauuu!!!" << std::endl;
}

