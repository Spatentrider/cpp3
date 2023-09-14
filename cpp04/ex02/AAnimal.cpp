#include "AAnimal.hpp"

Animal::Animal() : _type("Animal") 
{
	std::cout << "Animal: " << _type << " default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Animal: " << _type << " type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) 
{
	std::cout << "Animal: " << _type << " copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) 
{
	std::cout << "Animal: " << _type << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal: " << _type << " destructor called" << std::endl;
}

void	Animal::makeSound() const 
{
	std::cout << "Animal: " << _type << " generic sound" << std::endl;
}

std::string	Animal::getType() const 
{
	return this->_type;
}
