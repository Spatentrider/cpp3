#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Cat   : " << _type << " constructor called " << std::endl;
}

Cat::Cat(const Cat &other) 
{
	std::cout << "Cat   : " << _type << " copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() 
{
	std::cout << "Cat   : " << _type << " destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
	std::cout << "Cat   : " << _type << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void	Cat::makeSound() const 
{
	std::cout << "Cat   : " << _type << ": Miaawww!!!" << std::endl;
}
