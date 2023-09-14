#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	_hp = 100;
	_energy = 100;
	_attack = 30;
	std::cout << _name << ">> A new FragTrap named " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
	std::cout << _name << ">> FragTrap " << this->_name << " copied!" << std::endl;
}

FragTrap::~FragTrap() 
{
	std::cout << _name << ">> The FragTrap named " << _name << " has been destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_attack = other._attack;
	std::cout << _name << ">> FragTrap " << _name << " assigned!" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void) 
{
	std::cout << "Gimme five!" << std::endl;
}
