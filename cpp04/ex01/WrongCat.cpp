#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
	std::cout << _type << " constructor called " << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) 
{
	std::cout << type << " type constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << _type << " copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << _type << " destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << _type << ": Miaawww!!!" << std::endl;
}
