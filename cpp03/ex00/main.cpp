#include "ClapTrap.hpp"

int main() 
{
	ClapTrap clapTrap("C1");

	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);

	ClapTrap clapTrap2 = clapTrap;
	clapTrap2.attack("enemy");
	clapTrap2.takeDamage(2);
	clapTrap2.beRepaired(1);

	ClapTrap clapTrap3("C2");
	clapTrap3.attack("enemy");
	clapTrap3.takeDamage(4);
	clapTrap3.beRepaired(2);

	return 0;
}
