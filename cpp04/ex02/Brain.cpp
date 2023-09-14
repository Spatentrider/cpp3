#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other) 
{
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &other) 
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}
