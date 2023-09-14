#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) :
	_name(name), _hp(10), _energy(10), _attack(0) 
{
	std::cout << "A new ClapTrap named " << _name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "The ClapTrap named " << _name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) 
{
	*this = other;
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap& other ) 
{
	if (this != &other) {
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	return *this;
}


void	ClapTrap::attack( const std::string& target ) 
{
	if (_energy < 1) {
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " for " << _attack << " points of damage!" << std::endl;
	_energy--;
}

void	ClapTrap::takeDamage( unsigned int amount ) 
{
	if (_hp < amount) { 
		std::cout << "ClapTrap " << _name << " has been defeated!" << std::endl;
		_hp = 0;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hp -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount ) 
{
	if (_energy < 1) {
		std::cout << "ClapTrap " << _name << " has no energy left to be repaired!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
	_energy--;
	_hp += amount;
}
