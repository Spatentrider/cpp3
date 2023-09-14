#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") 
{
	std::cout << _type << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
	std::cout << _type << " type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) 
{
	std::cout << _type << " copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << _type << " desctructor called" << std::endl;
}

void	WrongAnimal::makeSound() const 
{
	std::cout << _type << " generic sound" << std::endl;
}

std::string	WrongAnimal::getType() const 
{
	return this->_type;
}
