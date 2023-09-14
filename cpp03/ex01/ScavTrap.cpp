#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hp = 100;
	_energy = 50;
	_attack = 20;
	std::cout << _name << ">> A new ScavTrap named " << _name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
	std::cout << _name << ">> ScavTrap " << this->_name << " copied!" << std::endl;
}

ScavTrap::~ScavTrap() 
{
	std::cout << _name << ">> The ScavTrap named " << _name << " has been destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << _name << ">> ScavTrap " << _name << " assigned!" << std::endl;
	return *this;
}

void ScavTrap::guardGate() 
{
	std::cout << _name << ">> ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
