#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	ClapTrap clapTrap("Clap");
	clapTrap.attack("enemy");
	clapTrap.takeDamage(50);
	clapTrap.beRepaired(30);

	ScavTrap scavTrap("Scav");
	scavTrap.attack("enemy");
	scavTrap.takeDamage(50);
	scavTrap.beRepaired(30);
	scavTrap.guardGate();

	FragTrap fragTrap("Frag");
	fragTrap.attack("enemy");
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(30);
	fragTrap.highFivesGuys();

	return 0;
}
